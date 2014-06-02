// Nirvana_ext.h

#ifndef H_NIR_EXT_DLL
#define H_NIR_EXT_DLL

#define WIN32_LEAN_AND_MEAN 
#include <Windows.h>
#include <vector>
#define BUILDING_NIR_EXT
#include "Nirvana_ext_export.h"

/* member variables */
extern std::vector<char*> RaceList;
extern std::vector<Plugin*> PluginList;

/* member functions */
HINSTANCE loadDll(LPCSTR lpFileName);
void loadPlugins();
void writeRaceSum();

#endif // H_NIR_EXT_DLL