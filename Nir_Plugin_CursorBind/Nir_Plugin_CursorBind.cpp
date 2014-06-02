// CursorLimit.cpp

#include "WindowsHook.h"
#include "PluginInfo.h"
#include <stdlib.h>

DWORD WINAPI hookWindow(LPVOID lpParam)
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
	bindCursor(wc3Hwnd, paramValue1);

	_wc3WndHook_fg=DeployWindowsHook(wc3Hwnd, hModule, paramValue1);
	if (_wc3WndHook_fg==NULL)
		MessageBox (0, "Deploy hook failed!", "Error", MB_ICONINFORMATION);
	else
		hookOn=true;
	SuspendThread(GetCurrentThread());	// suspend this thread so that the hook won't get killed
	return 0;
}

// TODO: Use unify method to pass paramValue into the hook procedure
void initialize()
{
	Plugin* pPlugin=getPluginInfo(_pluginName);
	if (pPlugin==NULL)
		return;
	if (pPlugin->parameterSize==0)
		return;

	for (int i=0; i < pPlugin->parameterSize; i++)
	{
		PluginParameter* pParam=pPlugin->pParameterList[i];
		if (strcmp(pParam->paramName, _paramName1)==0)
			paramValue1=atoi(pParam->paramValue);
		pParam = NULL;
	}
}

BOOL APIENTRY DllMain(HINSTANCE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	_selfHandle=hModule;
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		{
			initialize();
			_threadHandle=CreateThread(NULL, NULL, hookWindow, hModule, NULL, NULL);
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



