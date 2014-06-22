// Nirvana_ext.cpp

#include <iostream>
#include "Nirvana_ext.h"
#include "IniFileHandler.h"
#include "D3DHook.h"
#include "Command.h"
using namespace std;

std::vector<char*> RaceList;
std::vector<Plugin*> PluginList;

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

void writeRace()
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

	int i;
	for(i=0; i < size; i++)
	{
		char* race = RaceList[i];
		char* dest = (char*)(raceMenuOffest+20*i);
		strcpy(dest, race);
	}

	*(int*)(raceSumOffest)=i;
}


//==================================================================================================================================

BOOL APIENTRY DllMain (HINSTANCE hInst, DWORD reason, LPVOID reserved)
{
	if (reason==DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hInst);
		readIni(RaceList, PluginList);	// read settings & race list from nirvana.ini
		readCommands(RaceList);			// read from command line
		writeRace();					// write race list to memory
		loadDll("yd_jass_api.dll");     // load essential dll
		loadPlugins();                  // load dlls specified in nirvana.ini
		//loadDll("Nir_Plugin_Sample.dll");
		hookDirect3DCreate8();
	}
	return TRUE;
}