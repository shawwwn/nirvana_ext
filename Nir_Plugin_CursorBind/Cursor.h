// Cursor.h

#ifndef H_CURSOR
#define H_CURSOR

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
extern HWND _wc3Hwnd;
extern volatile int captionHeight;
extern volatile int xSizeFrame;
extern volatile int ySizeFrame;

//bind cursor
HWND bindCursor(HWND hwnd);
HWND bindCursor(LPCTSTR className, LPCTSTR windowName);
void bindCursorAsync(); // async to avoid optimization

// free cursor
void freeCursor();

#endif // H_CURSOR
