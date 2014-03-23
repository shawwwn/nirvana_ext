#include "Cursor.h"

HWND _wc3Hwnd=NULL;

volatile int captionHeight=-1;
volatile int xSizeFrame=-1;
volatile int ySizeFrame=-1;

void initWindowMetrics()
{
	if (_wc3Hwnd==NULL)
		_wc3Hwnd=FindWindow("Warcraft III", "Warcraft III");

	if (xSizeFrame==-1)
		xSizeFrame=GetSystemMetrics(SM_CXSIZEFRAME);
	if (ySizeFrame==-1)
		ySizeFrame=GetSystemMetrics(SM_CYSIZEFRAME);
	if (captionHeight==-1)
		captionHeight=GetSystemMetrics(SM_CYCAPTION);
}

DWORD WINAPI _bindCursorAsync(LPVOID lpParam)
{
	initWindowMetrics();
	RECT rect;
	GetWindowRect(_wc3Hwnd, &rect);
	rect.top+=(captionHeight+ySizeFrame);
	rect.bottom-=ySizeFrame;
	rect.left+=xSizeFrame;
	rect.right-=xSizeFrame;
	ClipCursor(&rect);
	return 0;
}

// create a new thread to avoid compiler's optimization
void bindCursorAsync()
{
	CreateThread(NULL, NULL, _bindCursorAsync, NULL, NULL, NULL);
}

HWND bindCursor(HWND hwnd)
{
	initWindowMetrics();
	RECT rect;
	GetWindowRect(hwnd, &rect);
	rect.top+=(captionHeight+ySizeFrame);
	rect.bottom-=ySizeFrame;
	rect.left+=xSizeFrame;
	rect.right-=xSizeFrame;
	if (ClipCursor(&rect))
		return hwnd;
	return NULL;
};

HWND bindCursor(LPCTSTR className, LPCTSTR windowName)
{
	_wc3Hwnd=FindWindow(className, windowName);
	if (_wc3Hwnd==NULL)
		return NULL;
	return bindCursor(_wc3Hwnd);
};

void freeCursor()
{
	ClipCursor(NULL);
};