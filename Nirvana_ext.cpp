// Nirvana_ext.cpp

#include "Nirvana_ext.h"
#include "IniFileHandler.h"
#include <iostream>
using namespace std;

// Loads dll(to whatever process it's attached to)
HINSTANCE loadDll(LPCSTR lpFileName)
{
	return LoadLibraryA(lpFileName);
}

void loadPlugins()
{
	int size=PluginList.size();
	if (size==0)
		return;

	for(int i=0; i < size; i++)
	{
		Plugin* plg_ptr=PluginList[i];
		loadDll(plg_ptr->pluginName);
	}
}

void writeRaceSum()
{
	int size=RaceList.size();
	if (size==0)
		return;

	DWORD raceMenuOffest=0xBB54B0;
	DWORD raceSumOffest=0xBB5480;
	HMODULE gameBaseAddress = GetModuleHandle("Nirvana.dll");
	raceMenuOffest = (DWORD)gameBaseAddress + raceMenuOffest;
	raceSumOffest = (DWORD)gameBaseAddress + raceSumOffest;
	if (gameBaseAddress==NULL)
	{
		MessageBox(NULL, "Unable to locate Nirvana.dll.", "Error!", MB_OK + MB_ICONERROR); 
		return;
	}

	// TODO: Use type cast instead of WriteProcessMemory.
	int i;
	for(i=0; i < size; i++)
	{
		char* race = RaceList[i];
		if (!WriteProcessMemory(INVALID_HANDLE_VALUE, (LPVOID)(raceMenuOffest+20*i), race, strlen(race), NULL))
			MessageBox(NULL, concatenate("Error cannot WriteProcessMemory! - RaceMenu: ", race), "Error!", MB_OK + MB_ICONERROR);
	}

	if (!WriteProcessMemory(INVALID_HANDLE_VALUE, (LPVOID)(raceSumOffest), &i, sizeof(i), NULL))
		MessageBox(NULL, "Error unable to write RaceSum.", "Error!", MB_OK + MB_ICONERROR);
}


//==================================================================================================================================

BOOL APIENTRY DllMain (HINSTANCE hInst, DWORD reason, LPVOID reserved)
{
	if (reason==DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hInst);
		readIni(RaceList, PluginList);	// read settings from nirvana.ini
		writeRaceSum();                 // write race name array to memory
		loadDll("yd_jass_api.dll");     // load essential dll
		loadPlugins();                  // load dlls specified in nirvana.ini
		//loadDll("Nir_Plugin_Sample.dll");
	}
	return TRUE;
}