// WindowsHook.h

#ifndef H_WINDOWS_HOOK
#define H_WINDOWS_HOOK
//#define WIN32_LEAN_AND_MEAN
//#include <windows.h>
#include "Cursor.h"

extern DWORD _wc3pThreadId;	// process thread id
extern DWORD _wc3wThreadId; // window thread id
extern HHOOK _wc3WndHook;
extern volatile bool hookOn;
extern volatile bool sysCmdOn;

// get thread Id from handle
DWORD GetWindowsThreadId(HWND hwnd);

// deploy hooks
HHOOK DeployWindowsHook(DWORD threadId, HINSTANCE selfHandle);
HHOOK DeployWindowsHook(HWND hwnd, HINSTANCE selfHandle);

// undeploy hook
BOOL RemoveWindowsHook(HHOOK wc3WndHook);
BOOL RemoveWindowsHook();

#endif // H_WINDOWS_HOOK
