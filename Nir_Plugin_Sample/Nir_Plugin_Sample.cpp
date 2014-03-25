// Nir_Plugin_Sample.cpp

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include "../Nirvana_ext_import.h"
#pragma comment(lib, "../Build/bin/Nirvana_ext.lib")
#pragma optimize("gsy", on)

volatile static HANDLE _selfHandle;

void printRaceList()
{
	std::cout << std::endl << "raceList:" << std::endl;
	for(int i=0; i<RaceList.size(); i++)
	{
		std::cout << RaceList[i] << std::endl;
	}
}

void initialize()
{
	printRaceList();
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
