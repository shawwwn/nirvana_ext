#include "IATHookHandler.h"

void __stdcall popMessageBox(UINT SDKVersion)
{
    MessageBox(NULL, "Direct3DCreate8 called!", "info", MB_OK);
    return;
}

void hookDirect3DCreate8()
{
	try
	{
		LoadLibrary("d3d8.dll");
		IATHookInstaller iat("Nirvana_ext.dll", "d3d8.dll", "Direct3DCreate8", popMessageBox);
		//iat.CleanUp();
	}
	catch (exception& e)
	{
		MessageBox(NULL, e.what(), "error", MB_OK);
	}
}