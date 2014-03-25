#ifndef H_NIR_EXT_DLL
#define H_NIR_EXT_DLL

#define WIN32_LEAN_AND_MEAN 
#include <Windows.h>
#include <vector>

/* exports */
struct __declspec(dllexport) Plugin {
	public:
		Plugin(void);
};

__declspec(dllexport) Plugin getPluginInfo(char* pluginName);


/* member variables */
__declspec(dllexport) extern std::vector<char*> RaceList;
__declspec(dllexport) extern std::vector<Plugin> PluginList;

/* member functions */
void writeRaceSum();

#endif