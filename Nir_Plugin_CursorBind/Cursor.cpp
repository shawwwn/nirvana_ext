#include "Cursor.h"

HWND _wc3Hwnd;
RECT _wc3Rect;


DWORD WINAPI _bindCursorAsync(LPVOID lpParam)
{
	int captionHeight=GetSystemMetrics(SM_CYCAPTION);
	//MessageBox (0, "Bind!", "Error", MB_ICONINFORMATION);
	HWND hwnd=FindWindow("Warcraft III", "Warcraft III");
	RECT rect;
	GetWindowRect(hwnd, &rect);
	rect.top+=(captionHeight+5);
	rect.bottom-=5;
	rect.left+=5;
	rect.right-=5;
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
	int captionHeight=GetSystemMetrics(SM_CYCAPTION);
	GetWindowRect(hwnd, &_wc3Rect);
	_wc3Rect.top+=(captionHeight+5);
	_wc3Rect.bottom-=5;
	_wc3Rect.left+=5;
	_wc3Rect.right-=5;
	if (ClipCursor(&_wc3Rect))
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