// CursorLimit.cpp

#include "WindowsHook.h"

#pragma comment(linker,"/entry:DllMain")
#pragma comment(linker, "/MERGE:.rdata=.text") 
#pragma comment(linker, "/MERGE:.data=.text") 
#pragma comment(linker, "/MERGE:code=.text") 
#pragma comment(linker,"/SECTION:.text,RWE")
#pragma optimize("gsy", on)

static HANDLE _selfHandle;
static HANDLE _threadHandle;
static HHOOK _wc3WndHook_fg;

DWORD WINAPI initialize(LPVOID lpParam)
{
	HWND wc3Hwnd=NULL;
	while (wc3Hwnd==NULL)
	{
		Sleep(200);
		wc3Hwnd=FindWindow("Warcraft III", "Warcraft III");
	}
	// wc3 main window created
	HINSTANCE hModule=(HINSTANCE)lpParam;
	//bindCursor("Warcraft III", "Warcraft III");
	bindCursor(wc3Hwnd);
	_wc3WndHook_fg=DeployWindowsHook(wc3Hwnd, hModule);
	if (_wc3WndHook_fg==NULL)
		MessageBox (0, "Deploy hook failed!", "Error", MB_ICONINFORMATION);
	else
		hookOn=true;
	SuspendThread(GetCurrentThread());	// suspend this thread so that the hook won't get killed
	return 0;
}

BOOL APIENTRY DllMain(HINSTANCE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	_selfHandle=hModule;
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		{
			_threadHandle=CreateThread(NULL, NULL, initialize, hModule, NULL, NULL);
			//HWND wc3Hwnd=bindCursor("Warcraft III", "Warcraft III");
			//_wc3WndHook_fg=DeployWindowsHook(wc3Hwnd, hModule);
			break;
		}
	case DLL_PROCESS_DETACH:
		RemoveWindowsHook(_wc3WndHook_fg);
		ResumeThread(_threadHandle);
		freeCursor();
		break;
	default:
		break;
	}
	return TRUE;
}



