#ifndef H_CURSOR
#define H_CURSOR

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
extern HWND _wc3Hwnd;
extern RECT _wc3Rect;

//bind cursor
HWND bindCursor(HWND hwnd);
HWND bindCursor(LPCTSTR className, LPCTSTR windowName);
void bindCursorAsync(); // async to avoid optimization

// free cursor
void freeCursor();

#endif // H_CURSOR
