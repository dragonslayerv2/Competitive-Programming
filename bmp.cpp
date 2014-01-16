
/*************************************************************************
	
	file created on:	2002/08/30   19:33
	filename: 			Bmp.cpp
	author:				Andreas Hartl

		visit http://www.runicsoft.com for updates and more information

	purpose:	functions to load raw bmp data,
	                      to save raw bmp data,
						  to convert RGB data to raw bmp data,
						  to convert raw bmp data to RGB data
						  and to use the WinAPI to select
							a bitmap into a device context

	file updated on 2010/09/13
		in the 8 years since i first wrote this the windows file functions
		have changed their input from char* to LPCTSTR. 
		Updated this in the code here

**************************************************************************/

#include <windows.h>
#include <stdio.h>       // for memset


/*******************************************************************
BYTE* ConvertRGBToBMPBuffer ( BYTE* Buffer, int width, 
		int height, long* newsize )


This function takes as input an array of RGB values, it's width
and height.
The buffer gets then transformed to an array that can be used
to write to a windows bitmap file. The size of the array
is returned in newsize, the array itself is the
return value of the function.
Both input and output buffers must be deleted by the
calling function.

The input buffer is expected to consist of width * height
RGB triplets. Thus the total size of the buffer is taken as
width * height * 3.

The function then transforms this buffer so that it can be written 
to a windows bitmap file:
First the RGB triplets are converted to BGR.
Then the buffer is swapped around since .bmps store
images uside-down.
Finally the buffer gets DWORD ( 32bit ) aligned, 
meaning that each scanline ( 3 * width bytes ) gets
padded with 0x00 bytes up to the next DWORD boundary


*******************************************************************/

BYTE* ConvertRGBToBMPBuffer ( BYTE* Buffer, int width, int height, long* newsize )
{

	// first make sure the parameters are valid
	if ( ( NULL == Buffer ) || ( width == 0 ) || ( height == 0 ) )
		return NULL;

	// now we have to find with how many bytes
	// we have to pad for the next DWORD boundary	

	int padding = 0;
	int scanlinebytes = width * 3;
	while ( ( scanlinebytes + padding ) % 4 != 0 )     // DWORD = 4 bytes
		padding++;
	// get the padded scanline width
	int psw = scanlinebytes + padding;
	
	// we can already store the size of the new padded buffer
	*newsize = height * psw;

	// and create new buffer
	BYTE* newbuf = new BYTE[*newsize];
	
	// fill the buffer with zero bytes then we dont have to add
	// extra padding zero bytes later on
	memset ( newbuf, 0, *newsize );

	// now we loop trough all bytes of the original buffer, 
	// swap the R and B bytes and the scanlines
	long bufpos = 0;   
	long newpos = 0;
	for ( int y = 0; y < height; y++ )
		for ( int x = 0; x < 3 * width; x+=3 )
		{
			bufpos = y * 3 * width + x;     // position in original buffer
			newpos = ( height - y - 1 ) * psw + x;           // position in padded buffer

			newbuf[newpos] = Buffer[bufpos+2];       // swap r and b
			newbuf[newpos + 1] = Buffer[bufpos + 1]; // g stays
			newbuf[newpos + 2] = Buffer[bufpos];     // swap b and r
		}

	return newbuf;
}

/***************************************************************
BYTE* ConvertBMPToRGBBuffer ( BYTE* Buffer, 
		int width, int height )

This function takes as input the data array
from a bitmap and its width and height.
It then converts the bmp data into an RGB array.
The calling function must delete both the input
and output arrays.
The size of the returned array will be 
width * height * 3
On error the returb value is NULL, else the
RGB array.


The Buffer is expected to be the exact data read out
from a .bmp file.  
The function will swap it around, since images
are stored upside-down in bmps.
The BGR triplets from the image data will
be converted to RGB.
And finally the function removes padding bytes.
The returned arraay consits then of
width * height RGB triplets.

*****************************************************************/

BYTE* ConvertBMPToRGBBuffer ( BYTE* Buffer, int width, int height )
{
	// first make sure the parameters are valid
	if ( ( NULL == Buffer ) || ( width == 0 ) || ( height == 0 ) )
		return NULL;

	// find the number of padding bytes
		
	int padding = 0;
	int scanlinebytes = width * 3;
	while ( ( scanlinebytes + padding ) % 4 != 0 )     // DWORD = 4 bytes
		padding++;
	// get the padded scanline width
	int psw = scanlinebytes + padding;

	// create new buffer
	BYTE* newbuf = new BYTE[width*height*3];
	
	// now we loop trough all bytes of the original buffer, 
	// swap the R and B bytes and the scanlines
	long bufpos = 0;   
	long newpos = 0;
	for ( int y = 0; y < height; y++ )
		for ( int x = 0; x < 3 * width; x+=3 )
		{
			newpos = y * 3 * width + x;     
			bufpos = ( height - y - 1 ) * psw + x;

			newbuf[newpos] = Buffer[bufpos + 2];       
			newbuf[newpos + 1] = Buffer[bufpos+1]; 
			newbuf[newpos + 2] = Buffer[bufpos];     
		}

	return newbuf;
}





/***********************************************
bool LoadBMPIntoDC ( HDC hDC, LPCTSTR bmpfile )

Takes in a device context and the name of a
bitmap to load. If an error occurs the function
returns false, else the contents of the bmp
are blitted to the HDC 

************************************************/

bool LoadBMPIntoDC ( HDC hDC, LPCTSTR bmpfile )
{
	// check if params are valid 
	if ( ( NULL == hDC  ) || ( NULL == bmpfile ) )
		return false;      

	// load bitmap into a bitmap handle
	HANDLE hBmp = LoadImage ( NULL, bmpfile, IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE );
	
	if ( NULL == hBmp )
		return false;        // failed to load image
 
	// bitmaps can only be selected into memory dcs:
	HDC dcmem = CreateCompatibleDC ( NULL );

	// now select bitmap into the memory dc
	if ( NULL == SelectObject ( dcmem, hBmp ) )
	{	// failed to load bitmap into device context
		DeleteDC ( dcmem ); 
		return false; 
	}

	
	// now get the bmp size
	BITMAP bm;
	GetObject ( hBmp, sizeof(bm), &bm );
	// and blit it to the visible dc
	if ( BitBlt ( hDC, 0, 0, bm.bmWidth, bm.bmHeight, dcmem,
		0, 0, SRCCOPY ) == 0 )
	{	// failed the blit
		DeleteDC ( dcmem ); 
		return false; 
	}
		   	
	DeleteDC ( dcmem );  // clear up the memory dc
	
	return true;
}



/***************************************************************
bool SaveBMP ( BYTE* Buffer, int width, int height, 
		long paddedsize, LPCTSTR bmpfile )

Function takes a buffer of size <paddedsize> 
and saves it as a <width> * <height> sized bitmap 
under the supplied filename.
On error the return value is false.

***************************************************************/

bool SaveBMP ( BYTE* Buffer, int width, int height, long paddedsize, LPCTSTR bmpfile )
{
	// declare bmp structures 
	BITMAPFILEHEADER bmfh;
	BITMAPINFOHEADER info;
	
	// andinitialize them to zero
	memset ( &bmfh, 0, sizeof (BITMAPFILEHEADER ) );
	memset ( &info, 0, sizeof (BITMAPINFOHEADER ) );
	
	// fill the fileheader with data
	bmfh.bfType = 0x4d42;       // 0x4d42 = 'BM'
	bmfh.bfReserved1 = 0;
	bmfh.bfReserved2 = 0;
	bmfh.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + paddedsize;
	bmfh.bfOffBits = 0x36;		// number of bytes to start of bitmap bits
	
	// fill the infoheader

	info.biSize = sizeof(BITMAPINFOHEADER);
	info.biWidth = width;
	info.biHeight = height;
	info.biPlanes = 1;			// we only have one bitplane
	info.biBitCount = 24;		// RGB mode is 24 bits
	info.biCompression = BI_RGB;	
	info.biSizeImage = 0;		// can be 0 for 24 bit images
	info.biXPelsPerMeter = 0x0ec4;     // paint and PSP use this values
	info.biYPelsPerMeter = 0x0ec4;     
	info.biClrUsed = 0;			// we are in RGB mode and have no palette
	info.biClrImportant = 0;    // all colors are important

	// now we open the file to write to
	HANDLE file = CreateFile ( bmpfile , GENERIC_WRITE, FILE_SHARE_READ,
		 NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL );
	if ( file == NULL )
	{
		CloseHandle ( file );
		return false;
	}
	
	// write file header
	unsigned long bwritten;
	if ( WriteFile ( file, &bmfh, sizeof ( BITMAPFILEHEADER ), &bwritten, NULL ) == false )
	{	
		CloseHandle ( file );
		return false;
	}
	// write infoheader
	if ( WriteFile ( file, &info, sizeof ( BITMAPINFOHEADER ), &bwritten, NULL ) == false )
	{	
		CloseHandle ( file );
		return false;
	}
	// write image data
	if ( WriteFile ( file, Buffer, paddedsize, &bwritten, NULL ) == false )
	{	
		CloseHandle ( file );
		return false;
	}
	
	// and close file
	CloseHandle ( file );

	return true;
}

/*******************************************************************
BYTE* LoadBMP ( int* width, int* height, long* size 
		LPCTSTR bmpfile )

The function loads a 24 bit bitmap from bmpfile, 
stores it's width and height in the supplied variables
and the whole size of the data (padded) in <size>
and returns a buffer of the image data 

On error the return value is NULL. 

  NOTE: make sure you [] delete the returned array at end of 
		program!!!
*******************************************************************/

BYTE* LoadBMP ( int* width, int* height, long* size, LPCTSTR bmpfile )
{
	// declare bitmap structures
	BITMAPFILEHEADER bmpheader;
	BITMAPINFOHEADER bmpinfo;
	// value to be used in ReadFile funcs
	DWORD bytesread;
	// open file to read from
	HANDLE file = CreateFile ( bmpfile , GENERIC_READ, FILE_SHARE_READ,
		 NULL, OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, NULL );
	if ( NULL == file )
		return NULL; // coudn't open file
	
	
	// read file header
	if ( ReadFile ( file, &bmpheader, sizeof ( BITMAPFILEHEADER ), &bytesread, NULL ) == false )
	{
		CloseHandle ( file );
		return NULL;
	}

	//read bitmap info

	if ( ReadFile ( file, &bmpinfo, sizeof ( BITMAPINFOHEADER ), &bytesread, NULL ) == false )
	{
		CloseHandle ( file );
		return NULL;
	}
	
	// check if file is actually a bmp
	if ( bmpheader.bfType != 'MB' )
	{
		CloseHandle ( file );
		return NULL;
	}

	// get image measurements
	*width   = bmpinfo.biWidth;
	*height  = abs ( bmpinfo.biHeight );

	// check if bmp is uncompressed
	if ( bmpinfo.biCompression != BI_RGB )
	{
		CloseHandle ( file );
		return NULL;
	}

	// check if we have 24 bit bmp
	if ( bmpinfo.biBitCount != 24 )
	{
		CloseHandle ( file );
		return NULL;
	}
	

	// create buffer to hold the data
	*size = bmpheader.bfSize - bmpheader.bfOffBits;
	BYTE* Buffer = new BYTE[ *size ];
	// move file pointer to start of bitmap data
	SetFilePointer ( file, bmpheader.bfOffBits, NULL, FILE_BEGIN );
	// read bmp data
	if ( ReadFile ( file, Buffer, *size, &bytesread, NULL ) == false )
	{
		delete [] Buffer;
		CloseHandle ( file );
		return NULL;
	}

	// everything successful here: close file and return buffer
	
	CloseHandle ( file );

	return Buffer;
}

void TestBMPCopy (LPCTSTR input, LPCTSTR output)
{
	int x, y;
	long s;
	BYTE* b = LoadBMP ( &x, &y, &s, input );
	SaveBMP ( b, x, y, s, output );
	delete [] b;
}

void TestBMPCopy2(LPCTSTR input, LPCTSTR output)
{
	int x, y;
	long s, s2;
	BYTE* a = LoadBMP ( &x, &y, &s, input );
	BYTE* b = ConvertBMPToRGBBuffer ( a, x, y );
	BYTE* c = ConvertRGBToBMPBuffer ( b, x, y, &s2 );	
	SaveBMP ( c, x, y, s2, output );
	delete [] a;
	delete [] b;
	delete [] c;
}

int main ()
{
	 //TestBMPCopy (L"test.bmp", L"copy.bmp");
	TestBMPCopy2 ("test.bmp", "copy.bmp");
}
