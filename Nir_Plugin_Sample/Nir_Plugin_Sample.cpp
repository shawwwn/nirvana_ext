// Nir_Plugin_Sample.cpp

#include <iostream>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include "../Nirvana_ext_export.h"
#pragma comment(lib, "../Build/bin/Nirvana_ext.lib")

volatile static HANDLE _selfHandle;
const char* _PluginName="Nir_Plugin_Sample.dll";

// retrieve a single plugin setting
void printSelfSetting()
{
	std::cout << "self information - from SampleDll" << std::endl;

	Plugin* pPlugin=getPluginInfo(_PluginName);
	if (pPlugin==NULL)
		return;
	std::cout << "self Plugin Name: " << pPlugin->pluginName << std::endl;
	if (pPlugin->parameterSize==0)
		return;
	for (int i=0; i < pPlugin->parameterSize; i++)
	{
		PluginParameter* pParam = pPlugin->pParameterList[i];
		std::cout << "paramName: " << pParam->paramName << " - paramValue: " << pParam->paramValue << std::endl;
		double value=atof(pParam->paramValue);
		std::cout << "double: " << value << std::endl;
		pParam = NULL;
	}
}

void initialize()
{
	printSelfSetting();
	/* Add your own logics */
}

BOOL APIENTRY DllMain(HANDLE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	_selfHandle=hModule;
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		initialize();
		break;
	case DLL_PROCESS_DETACH:
		break;
	default:
		break;
	}
    return TRUE;
}
