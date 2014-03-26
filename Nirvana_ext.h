// Nirvana_ext.h

#ifndef H_NIR_EXT_DLL
#define H_NIR_EXT_DLL

#define WIN32_LEAN_AND_MEAN 
#include <Windows.h>
#include <vector>

/* exports */
struct __declspec(dllexport) PluginParameter {
	public:
		PluginParameter(char* name, char* value, bool allocNew);
		char* paramName;
		char* paramValue;
};

struct __declspec(dllexport) Plugin {
	public:
		char* pluginName;
		Plugin(char* name);
		std::vector<PluginParameter*> paramList;
};

__declspec(dllexport) Plugin getPluginInfo(char* pluginName);


/* member variables */
__declspec(dllexport) extern std::vector<char*> RaceList;
__declspec(dllexport) extern std::vector<Plugin*> PluginList;

/* member functions */
HINSTANCE loadDll(LPCSTR lpFileName);
void loadPlugins();
void writeRaceSum();

#endif // H_NIR_EXT_DLL