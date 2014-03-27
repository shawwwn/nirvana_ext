#include "WindowsHook.h"

DWORD _wc3pThreadId;
DWORD _wc3wThreadId;
HHOOK _wc3WndHook;
volatile bool sysCmdOn=false;
volatile bool hookOn=false;

// hook procedure
LRESULT WINAPI CallWndProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode < 0)  // do not process message 
		return CallNextHookEx(_wc3WndHook, nCode, wParam, lParam);

	if (nCode==HC_ACTION)
	{
		CWPSTRUCT* msg=(CWPSTRUCT*)lParam;
		switch (msg->message)
		{
		// TODO: Add logic to deal with WM_CAPTURECHANGED being called multipled times
		case WM_SYSCOMMAND:
			if (wParam == SC_MAXIMIZE) {
				hookOn = false;
				sysCmdOn=false;
			}
			else sysCmdOn=true;
			break;
		case WM_CAPTURECHANGED:
			if (!sysCmdOn)
			{
				if (!hookOn)
				{
					hookOn=true;
					bindCursorAsync(); // bind cursor when mouse enter the screen
				}
			}
			else
				sysCmdOn=false;
			break;
		case WM_SIZE:
			hookOn=true;
			sysCmdOn=false;
			bindCursorAsync(); // bind cursor when finish sizing
			break;
		case WM_EXITSIZEMOVE:
			hookOn=true;
			sysCmdOn=false;
			bindCursorAsync(); // bind cursor when finish moving
			break;
		case WM_SETFOCUS:
			if (hookOn)
				bindCursorAsync(); // bind cursor when gain focus
			break;
		case WM_KILLFOCUS:
			hookOn=false;
			freeCursor(); // free cursor when lose focus
			break;
		default:
			break;
		}
	}
	return CallNextHookEx(_wc3WndHook, nCode, wParam, lParam);
}

DWORD GetWindowsThreadId(HWND hwnd)
{
	_wc3wThreadId=GetWindowThreadProcessId(hwnd, &_wc3pThreadId);
	return _wc3wThreadId;
};

HHOOK DeployWindowsHook(DWORD wThreadId, HINSTANCE selfHandle, int margin)
{
	if (wThreadId==0)
		return NULL;
	cursorMargin=margin;	// pass the paramValue into cursor.cpp 

	//_wc3WndHook=SetWindowsHookEx(WH_CALLWNDPROC, (HOOKPROC)CallWndProc, GetModuleHandle("CursorLimit.dll"), wThreadId);
	#ifdef _DEBUG  
	_wc3WndHook=SetWindowsHookEx(WH_CALLWNDPROC, (HOOKPROC)CallWndProc, selfHandle, wThreadId); // deploy to other(process) thread
    #else 
	_wc3WndHook=SetWindowsHookEx(WH_CALLWNDPROC, (HOOKPROC)CallWndProc, NULL, wThreadId); // deploy to own(parent) thread
	#endif
	
	return _wc3WndHook;
};

HHOOK DeployWindowsHook(HWND hwnd, HINSTANCE selfHandle, int margin)
{
	return DeployWindowsHook(GetWindowsThreadId(hwnd), selfHandle, margin);
};

BOOL RemoveWindowsHook(HHOOK wc3WndHook)
{
	return UnhookWindowsHookEx(wc3WndHook);
};

BOOL RemoveWindowsHook()
{
	return UnhookWindowsHookEx(_wc3WndHook);
};

