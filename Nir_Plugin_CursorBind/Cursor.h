// Cursor.h

#ifndef H_CURSOR
#define H_CURSOR

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
extern HWND _wc3Hwnd;
extern volatile int captionHeight;
extern volatile int xSizeFrame;
extern volatile int ySizeFrame;
extern volatile int cursorMargin;

//bind cursor
void initWindowMetrics();
HWND bindCursor(HWND hwnd, int margin);
HWND bindCursor(LPCTSTR className, LPCTSTR windowName, int margin);
DWORD WINAPI _bindCursorAsync(LPVOID lpParam);
void bindCursorAsync(); // async to avoid optimization

// free cursor
void freeCursor();

#endif // H_CURSOR
