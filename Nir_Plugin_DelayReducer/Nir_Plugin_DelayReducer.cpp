// Nir_Plugin_DelayReducer.cpp

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include "PluginInfo.h"
#include <stdlib.h>
#define ADDRESS unsigned int

// write memory
void changeDelay(int singlePlayerDelay, int lanDelay, int bnetDelay)
{
	ADDRESS gameBaseAddress = (ADDRESS)GetModuleHandle("nirvana.dll");
	LPVOID localAddress = (LPVOID*)(gameBaseAddress+0x660F01);      // 0x64 (100ms)
	LPVOID lanAddress = (LPVOID*)(gameBaseAddress+0x661A91);        // 0x64 (100ms)
	LPVOID netAddress = (LPVOID*)(gameBaseAddress+0x65DE41);        // 0x0FA (250ms)

	DWORD dwOldProtect;
	if (VirtualProtect(localAddress, sizeof(singlePlayerDelay), PAGE_EXECUTE_READWRITE, &dwOldProtect))
		*(DWORD*)localAddress = singlePlayerDelay;                  // 35ms

	if (VirtualProtect(lanAddress, sizeof(lanDelay), PAGE_EXECUTE_READWRITE, &dwOldProtect))
		*(DWORD*)lanAddress = lanDelay;                             // 35ms

	if (VirtualProtect(netAddress, sizeof(bnetDelay), PAGE_EXECUTE_READWRITE, &dwOldProtect))
		*(DWORD*)netAddress = bnetDelay;                            // 100ms
}

// retrieve plugin info
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
		else if (strcmp(pParam->paramName, _paramName2)==0)
			paramValue2=atoi(pParam->paramValue);
		else if (strcmp(pParam->paramName, _paramName3)==0)
			paramValue3=atoi(pParam->paramValue);
		pParam = NULL;
	}
}

BOOL APIENTRY DllMain(HANDLE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	_selfHandle=hModule;
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		initialize();
		changeDelay(paramValue1, paramValue2, paramValue3);
		break;
	case DLL_PROCESS_DETACH:
		break;
	default:
		break;
	}
    return TRUE;
}

