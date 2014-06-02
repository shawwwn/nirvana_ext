#include "D3DHook.h"

inlineFuncHook d3dHook;

VOID* __stdcall GetProcAddressFake(HMODULE lib, const char* name)
{
	if (strcmp(name, "Direct3DCreate8")==0)
	{
		HMODULE hModule = GetModuleHandle(DX_DLL_NAME);
		if (hModule!=NULL)
			return GetProcAddress(hModule, "Direct3DCreate8to9");
	}

	return GetProcAddress(lib, name);
}

void hookDirect3DCreate8()
{
	Plugin* plg=getPluginInfo(DX_DLL_NAME);
	if (plg!=NULL)
		d3dHook.hook(RVA_Direct3DCreate8, GetProcAddressFake);
}
