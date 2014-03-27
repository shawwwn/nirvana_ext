// Nir_Plugin_Sample.cpp

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include "../Nirvana_ext_import.h"
#pragma comment(lib, "../Build/bin/Nirvana_ext.lib")

volatile static HANDLE _selfHandle;
const char* _PluginName="Nir_Plugin_Sample";

// looping through the race list from plugin dll
void printRaceList()
{
	std::cout << std::endl << "display raceList - from SampleDll" << std::endl;
	for(int i=0; i<RaceList.size(); i++)
	{
		std::cout << RaceList[i] << std::endl;
	}
}

// looping through the plugin settings from plugin dll
void printPluginList()
{
	std::cout << std::endl << "display pluginList - from SampleDll" << std::endl;
	for(int i=0; i < PluginList.size(); i++)
	{
		Plugin* plg_ptr=PluginList[i];
		std::cout << plg_ptr->pluginName << std::endl;
		if (plg_ptr->paramList.size()>0)
		{
			for (int j=0; j < plg_ptr->paramList.size(); j++)
			{
				PluginParameter* param_ptr = plg_ptr->paramList[j];
				std::cout << "paramName: " << param_ptr->paramName << " - paramValue: " << param_ptr->paramValue << std::endl;
			}
		}
	}
}

// retrieve a single plugin setting
void printSelfSetting()
{
	std::cout << "self information - from SampleDll" << std::endl;
	char* selfName="Nir_Plugin_Sample.dll"; 
	Plugin* self=getPluginInfo(selfName);
	if (self==NULL)
		return;
	std::cout << "self Plugin Name: " << self->pluginName << std::endl;
	int size=self->paramList.size();
	if (size==0)
		return;
	for (int i=0; i < size; i++)
	{
		PluginParameter* param_ptr=self->paramList[i];
		std::cout << "paramName: " << param_ptr->paramName << " - paramValue: " << param_ptr->paramValue << std::endl;
		int value=atoi(param_ptr->paramValue);
		std::cout << "int value: " << value << std::endl;
	}
}

void initialize()
{
	printRaceList();
	printPluginList();
	std::cout << std::endl;
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
