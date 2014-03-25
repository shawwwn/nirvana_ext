// Nirvana_ext.cpp

#include "Nirvana_ext.h"
#include "IniFileHandler.h"
#include <iostream>
using namespace std;

//#pragma comment(linker, "/ENTRY:DllMain")

Plugin::Plugin(void)
{
	// TODO: Add constructor
}

// Writes amount of race to memory
void writeRaceSum()
{
	ifstream f1("Nirvana.ini", ios::in);
	if(!f1)return;
	int i=0;
	DWORD dwRaceMenu=0x00BB54B0;
	DWORD dwRaceSum=0x00BB5480;
	
	//HMODULE dwGameModule = GetModu leHandle(NULL);
	HMODULE dwGameModule = GetModuleHandle("Nirvana.dll");
	dwRaceMenu = (DWORD)dwGameModule + dwRaceMenu;
	dwRaceSum = (DWORD)dwGameModule + dwRaceSum;
	
	if (dwGameModule==NULL)
	{
		MessageBox(NULL, "Cant locate game.dll", "Error!", MB_OK + MB_ICONERROR); 
		return;
	}
	
	//read from text file and write memory
	while(!f1.eof())
	{
		char *cValue = new char[20];
		f1.getline(cValue,20);
		cValue=trim(cValue);
		if (cValue[0]!=0)
		{
			DWORD newdatasize = strlen(cValue); 
			if (WriteProcessMemory(INVALID_HANDLE_VALUE, (LPVOID)(dwRaceMenu+20*i), cValue, newdatasize, NULL))
			{
			  //MessageBox(NULL, "WriteProcessMemory is a success!", "Success!", MB_OK + MB_ICONINFORMATION); 
			}
			else
			{
				MessageBox(NULL, concatenate("Error cannot WriteProcessMemory! - RaceMenu: ", cValue), "Error!", MB_OK + MB_ICONERROR); 
			}
			i++;
		}
	}
	f1.close();

	//write race sum
	if (WriteProcessMemory(INVALID_HANDLE_VALUE, (LPVOID)(dwRaceSum), &i, 1, NULL))
	{
		//MessageBox(NULL, "WriteRaceMemory is a success!", "Success!", MB_OK + MB_ICONINFORMATION); 
	}
	else
	{
		MessageBox(NULL, "Error cannot WriteProcessMemory! - RaceSum", "Error!", MB_OK + MB_ICONERROR); 
	}
}

// Loads dll(to whatever process it's attached to)
HINSTANCE loadDll(LPCSTR lpFileName)
{
	return LoadLibraryA(lpFileName);
}


//==================================================================================================================================

BOOL APIENTRY DllMain (HINSTANCE hInst, DWORD reason, LPVOID reserved)
{
	if (reason==DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hInst);
		/*
		writeRaceSum();
		loadDll("yd_jass_api.dll");
		loadDll("Nir_Plugin_CursorBind.dll");
		loadDll("Nir_Plugin_Manabar.dll");
		loadDll("Nir_Plugin_DelayReducer.dll");
		*/
		vector<char*> raceList;
		readIni(raceList);
		cout << endl << "raceList:" << endl;
		for(int i=0; i<raceList.size(); i++){
			cout << raceList[i] << endl;
		}
	}
	return TRUE;
}