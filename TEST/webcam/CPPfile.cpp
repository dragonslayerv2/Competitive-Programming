#include "VideoCapture.h"

//VIDEODEVICE
//public
VideoDevice::VideoDevice()
{
	friendlyname = (char*) calloc(1, MAX_DEVICE_NAME * sizeof(char));
	filtername =  (WCHAR*) calloc(1, MAX_DEVICE_NAME * sizeof(WCHAR));
	filter = 0;
}

VideoDevice::~VideoDevice()
{
	free(friendlyname);
	free(filtername);
}

const char* VideoDevice::GetFriendlyName()
{
	return friendlyname;
}



//VIDEOCAPTURE
//public
VideoCapture::VideoCapture(VideoCaptureCallback cb)
{
	CoInitialize(NULL);

	playing = false;
	current = 0;
	callbackhandler = new CallbackHandler(cb);
	devices = new VideoDevice[MAX_DEVICES];

	InitializeGraph();
	SetSourceFilters();
	SetSampleGrabber();
	SetNullRenderer();
}

VideoCapture::~VideoCapture()
{
	delete callbackhandler;
	delete[] devices;
}

VideoDevice* VideoCapture::GetDevices()
{
	return devices;
}

int VideoCapture::NumDevices()
{
	return num_devices;
}

void VideoCapture::Select(VideoDevice* dev)
{
	HRESULT hr;
	LONGLONG start=MAXLONGLONG, stop=MAXLONGLONG;
	bool was_playing = playing;

	if (!dev->filter) throw E_INVALIDARG;

	//temporary stop
	if (playing) Stop();

	if (current)
	{
		//remove and add the filters to force disconnect of pins
		graph->RemoveFilter(current->filter);
		graph->RemoveFilter(samplegrabberfilter);

		graph->AddFilter(samplegrabberfilter,L"Sample Grabber");
		graph->AddFilter(current->filter, current->filtername);
	}

	start = 0;
	current = dev;

	//connect graph with current source filter
	#ifdef SHOW_DEBUG_RENDERER
	hr = capture->RenderStream(&PIN_CATEGORY_CAPTURE, &MEDIATYPE_Video, current->filter, samplegrabberfilter, NULL);
	#else
	hr = capture->RenderStream(&PIN_CATEGORY_CAPTURE, &MEDIATYPE_Video, current->filter, samplegrabberfilter, nullrenderer);
	#endif
	if (hr != S_OK) throw hr;

	//start streaming
	hr = capture->ControlStream(&PIN_CATEGORY_CAPTURE, &MEDIATYPE_Video, current->filter, &start, &stop, 1,2);
	if (hr < 0) throw hr;

	//restart
	if (was_playing) Start();
}

void VideoCapture::Start()
{
	HRESULT hr;

	hr = control->Run();
	if (hr < 0) throw hr;

	playing = true;
}

void VideoCapture::Stop()
{
	HRESULT hr;

	hr = control->StopWhenReady();
	if (hr < 0) throw hr;

	playing = false;
}

//protected
void VideoCapture::InitializeGraph()
{
	HRESULT hr;

	//create the FilterGraph
	hr = CoCreateInstance(CLSID_FilterGraph,NULL,CLSCTX_INPROC_SERVER,IID_IFilterGraph2,(void**) &graph);
	if (hr < 0) throw hr;

	//create the CaptureGraphBuilder
	hr = CoCreateInstance(CLSID_CaptureGraphBuilder2,NULL,CLSCTX_INPROC_SERVER,IID_ICaptureGraphBuilder2,(void**) &capture);
	if (hr < 0) throw hr;

	//get the controller for the graph
	hr = graph->QueryInterface(IID_IMediaControl, (void**) &control);
	if (hr < 0) throw hr;

	capture->SetFiltergraph(graph);
}

void VideoCapture::SetSourceFilters()
{
	HRESULT hr;
	VARIANT name;
	LONGLONG start=MAXLONGLONG, stop=MAXLONGLONG;

	unsigned long dev_count;

	ICreateDevEnum*		dev_enum;
	IEnumMoniker*		enum_moniker;
	IMoniker*			moniker;
	IPropertyBag*		pbag;

	//create an enumerator for video input devices
	hr = CoCreateInstance(CLSID_SystemDeviceEnum, NULL,CLSCTX_INPROC_SERVER,IID_ICreateDevEnum,(void**) &dev_enum);
	if (hr < 0) throw hr;

	hr = dev_enum->CreateClassEnumerator(CLSID_VideoInputDeviceCategory,&enum_moniker,NULL);
	if (hr < 0) throw hr;
	if (hr == S_FALSE) return; //no devices found

	//get devices (max 8)
	num_devices = 0;
	enum_moniker->Next(MAX_DEVICES, &moniker, &dev_count);
	for (unsigned int i=0; i<dev_count; i++)
	{
		//get properties
		hr = moniker[i].BindToStorage(0, 0, IID_IPropertyBag, (void**) &pbag);
		if (hr >= 0)
		{
			VariantInit(&name);

			//get the description
			hr = pbag->Read(L"Description", &name, 0);
			if (hr < 0) hr = pbag->Read(L"FriendlyName", &name, 0);
			if (hr >= 0)
			{
				//Initialize the VideoDevice struct
				VideoDevice* dev = devices+num_devices++;
				BSTR ptr = name.bstrVal;

				for (int c = 0; *ptr; c++, ptr++)
				{
					//bit hacky, but i don't like to include ATL
					dev->filtername[c] = *ptr;
					dev->friendlyname[c] = *ptr & 0xFF;
				}

				//add a filter for the device
				hr = graph->AddSourceFilterForMoniker(moniker+i, 0, dev->filtername, &dev->filter);
				if (hr != S_OK) num_devices--;
			}
			VariantClear(&name);
			pbag->Release();
		}
		moniker[i].Release();
	}
}

void VideoCapture::SetSampleGrabber()
{
	HRESULT hr;

	hr = CoCreateInstance(CLSID_SampleGrabber, NULL, CLSCTX_INPROC_SERVER,IID_IBaseFilter,(void**)&samplegrabberfilter);
	if (hr < 0) throw hr;

	hr = graph->AddFilter(samplegrabberfilter, L"Sample Grabber");
	if (hr != S_OK) throw hr;

	hr = samplegrabberfilter->QueryInterface(IID_ISampleGrabber, (void**)&samplegrabber);
	if (hr != S_OK) throw hr;

	//set the media type
	AM_MEDIA_TYPE mt;
	memset(&mt, 0, sizeof(AM_MEDIA_TYPE));

	mt.majortype	= MEDIATYPE_Video;
	mt.subtype		= MEDIASUBTYPE_RGB24;
	// setting the above to 32 bits fails consecutive Select for some reason
	// and only sends one single callback (flush from previous one ???)
	// must be deeper problem. 24 bpp seems to work fine for now.

	callbackhandler->SetMediaType(&mt);
	hr = samplegrabber->SetMediaType(&mt);
	if (hr != S_OK) throw hr;

	samplegrabber->SetCallback(callbackhandler,0);
}

void VideoCapture::SetNullRenderer()
{
	HRESULT hr;

	hr = CoCreateInstance(CLSID_NullRenderer,NULL,CLSCTX_INPROC_SERVER,IID_IBaseFilter,(void**) &nullrenderer);
	if (hr < 0) throw hr;

	graph->AddFilter(nullrenderer, L"Null Renderer");
}



//CALLBACKHANDLER
//public
VideoCapture::CallbackHandler::CallbackHandler(VideoCaptureCallback cb)
{
	callback = cb;
}

VideoCapture::CallbackHandler::~CallbackHandler()
{
}

void VideoCapture::CallbackHandler::SetMediaType(AM_MEDIA_TYPE* am)
{
	if (am->subtype == MEDIASUBTYPE_RGB555) bitpixel = 16;
	else if (am->subtype == MEDIASUBTYPE_RGB24) bitpixel = 24;
	else if (am->subtype == MEDIASUBTYPE_RGB32) bitpixel = 32;
}

HRESULT VideoCapture::CallbackHandler::SampleCB(double time, IMediaSample *sample)
{
	HRESULT hr;
	AM_MEDIA_TYPE* mt;
	unsigned char* buffer;

	hr = sample->GetPointer((BYTE**)&buffer);
	if (hr != S_OK) return S_OK;

	hr = sample->GetMediaType(&mt);
	if (hr < 0) return S_OK;
	if (hr == S_OK) SetMediaType(mt);

	callback(buffer, sample->GetActualDataLength(), bitpixel);
	return S_OK;
}

HRESULT VideoCapture::CallbackHandler::BufferCB(double time, BYTE *buffer, long len)
{
	return S_OK;
}

HRESULT VideoCapture::CallbackHandler::QueryInterface(const IID &iid, LPVOID *ppv)
{
	if( iid == IID_ISampleGrabberCB || iid == IID_IUnknown )
	{
		*ppv = (void *) static_cast<ISampleGrabberCB*>( this );
		return S_OK;
	}
	return E_NOINTERFACE;
}

ULONG VideoCapture::CallbackHandler::AddRef()
{
	return 1;
}

ULONG VideoCapture::CallbackHandler::Release()
{
	return 2;
}



