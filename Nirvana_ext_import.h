// Nirvana_ext_import.h
// For other program linking this dll(import) only!

#ifndef H_NIR_EXT_IMP_DLL
#define H_NIR_EXT_IMP_DLL

#include <vector>
#include <iostream>

/* import structs */
struct __declspec(dllimport) PluginParameter {
	public:
		PluginParameter(char* name, char* value, bool allocNew);
		char* paramName;
		char* paramValue;
};

struct __declspec(dllimport) Plugin {
	public:
		Plugin(char* name);
		char* pluginName;
		std::vector<PluginParameter*> paramList;
};

/* import global variables */
__declspec(dllimport) extern std::vector<char*> RaceList;
__declspec(dllimport) extern std::vector<Plugin*> PluginList;

/* import functions */
__declspec(dllimport) Plugin* getPluginInfo(const char* pluginName);

#endif // H_NIR_EXT_IMP_DLL