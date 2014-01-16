#pragma once
#pragma comment(lib, "strmiids")

#define SKIP_DXTRANS
#define SHOW_DEBUG_RENDERER

/* If you are having the problem you can't open dxtrans.h:
 * Open qedit.h and add this to the start of the file:
 *
 * #ifdef SKIP_DXTRANS
 * #define __IDxtAlphaSetter_INTERFACE_DEFINED__
 * #define __IDxtJpeg_INTERFACE_DEFINED__
 * #define __IDxtKey_INTERFACE_DEFINED__
 * #define __IDxtCompositor_INTERFACE_DEFINED__
 * #endif
 *
 * Also replace the line
 * #include "dxtrans.h"
 * with:
 * #ifndef SKIP_DXTRANS
 * #include "dxtrans.h"
 * #endif
 */

#include <windows.h>
#include <dshow.h>
#include <qedit.h>

#ifndef MAXLONGLONG
#define MAXLONGLONG 0x7FFFFFFFFFFFFFFF
#endif

#ifndef MAX_DEVICES
#define MAX_DEVICES 8
#endif

#ifndef MAX_DEVICE_NAME
#define MAX_DEVICE_NAME 80
#endif

typedef struct
{
	unsigned char R;
	unsigned char G;
	unsigned char B;
} RGB;

typedef void (*VideoCaptureCallback)(unsigned char* data, int len, int bitsperpixel);

class VideoDevice
{
public:
	VideoDevice();
	~VideoDevice();

	const char* GetFriendlyName();

private:
	char*			friendlyname;
	WCHAR*			filtername;
	IBaseFilter*	filter;
	friend class	VideoCapture;
};

class VideoCapture
{
public:
	VideoCapture(VideoCaptureCallback callback);
	~VideoCapture();

	VideoDevice* GetDevices();
	int  NumDevices();

	void Select(VideoDevice* dev);
	void Start();
	void Stop();

protected:
	void InitializeGraph();
	void SetSourceFilters();
	void SetSampleGrabber();
	void SetNullRenderer();
	void ConnectFilters();

private:
	IFilterGraph2*			graph;
	ICaptureGraphBuilder2*	capture;
	IMediaControl*			control;

	IBaseFilter*			nullrenderer;
	IBaseFilter*			samplegrabberfilter;
	ISampleGrabber*			samplegrabber;

	bool					playing;

	VideoDevice*			devices;
	VideoDevice*			current;

	int						num_devices;

	class CallbackHandler : public ISampleGrabberCB
	{
	public:
		CallbackHandler(VideoCaptureCallback cb);
		~CallbackHandler();

		void SetMediaType(AM_MEDIA_TYPE* am);

		virtual HRESULT __stdcall SampleCB(double time, IMediaSample* sample);
		virtual HRESULT __stdcall BufferCB(double time, BYTE* buffer, long len);
		virtual HRESULT __stdcall QueryInterface( REFIID iid, LPVOID *ppv );
		virtual ULONG	__stdcall AddRef();
		virtual ULONG	__stdcall Release();

	private:
		int						bitpixel;
		VideoCaptureCallback	callback;

	} *callbackhandler;
};
