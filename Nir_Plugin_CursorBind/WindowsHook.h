// WindowsHook.h

#ifndef H_WINDOWS_HOOK
#define H_WINDOWS_HOOK
#include "Cursor.h"

extern DWORD _wc3pThreadId;	// process thread id
extern DWORD _wc3wThreadId; // window thread id
extern HHOOK _wc3WndHook;
extern volatile bool sysCmdOn;
extern volatile bool hookOn;

// get thread Id from handle
DWORD GetWindowsThreadId(HWND hwnd);

// deploy hooks
HHOOK DeployWindowsHook(DWORD threadId, HINSTANCE selfHandle, int margin);
HHOOK DeployWindowsHook(HWND hwnd, HINSTANCE selfHandle, int margin);

// undeploy hook
BOOL RemoveWindowsHook(HHOOK wc3WndHook);
BOOL RemoveWindowsHook();

#endif // H_WINDOWS_HOOK
