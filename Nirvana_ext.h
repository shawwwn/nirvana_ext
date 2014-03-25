#ifdef DLL_EXPORTS
#define DLL_EXPORTS __declspec(dllexport)
#else
#define DLL_EXPORTS __declspec(dllimport)
#endif

#define WIN32_LEAN_AND_MEAN 
#include <Windows.h>
#include <vector>

/* exports */
struct DLL_EXPORTS Plugin {
	public:
		Plugin(void);
};

DLL_EXPORTS Plugin getPluginInfo(char* pluginName);


/* member variables */
volatile std::vector<Plugin> PluginList;

/* member functions */
void writeRaceSum();