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
		// TODO: Add logic to deal with clicking on the system bar but not moving window
		case WM_SYSCOMMAND:
			if (wParam == SC_MAXIMIZE) {
				hookOn = false;
				sysCmdOn=false;
			}
			else sysCmdOn=true;
			break;
		case WM_CAPTURECHANGED:
			if (!sysCmdOn && !hookOn)
			{
				hookOn=true;
				bindCursorAsync(); // bind cursor when mouse enter the screen
			}
			break;
		case WM_ENTERSIZEMOVE:
			hookOn=true;
			sysCmdOn=false;
			//bindCursorAsync(); // bind cursor when finish sizing
			break;
		case WM_EXITSIZEMOVE:
			hookOn=true;
			sysCmdOn=false;
			bindCursorAsync(); // bind cursor when finish moving
			break;
		case WM_SETFOCUS:
			if (hookOn)
			{
				bindCursorAsync(); // bind cursor when gain focus
			}
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

HHOOK DeployWindowsHook(DWORD wThreadId, HINSTANCE selfHandle)
{
	if (wThreadId==0)
		return NULL;

	//_wc3WndHook=SetWindowsHookEx(WH_CALLWNDPROC, (HOOKPROC)CallWndProc, GetModuleHandle("CursorLimit.dll"), wThreadId);
	#ifdef _DEBUG  
	_wc3WndHook=SetWindowsHookEx(WH_CALLWNDPROC, (HOOKPROC)CallWndProc, selfHandle, wThreadId); // deploy to other(process) thread
    #else 
	_wc3WndHook=SetWindowsHookEx(WH_CALLWNDPROC, (HOOKPROC)CallWndProc, NULL, wThreadId); // deploy to own(parent) thread
	#endif
	
	return _wc3WndHook;
};

HHOOK DeployWindowsHook(HWND hwnd, HINSTANCE selfHandle)
{
	return DeployWindowsHook(GetWindowsThreadId(hwnd), selfHandle);
};

BOOL RemoveWindowsHook(HHOOK wc3WndHook)
{
	return UnhookWindowsHookEx(wc3WndHook);
};

BOOL RemoveWindowsHook()
{
	return UnhookWindowsHookEx(_wc3WndHook);
};

