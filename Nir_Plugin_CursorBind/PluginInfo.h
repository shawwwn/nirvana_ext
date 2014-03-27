#ifndef H_PLUGIN_INFO
#define H_PLUGIN_INFO

#include "../Nirvana_ext_import.h"
#pragma comment(lib, "../Build/bin/Nirvana_ext.lib")

// plugin info
volatile static HANDLE _selfHandle;
volatile static HANDLE _threadHandle;
volatile static HHOOK _wc3WndHook_fg;

extern const char* _pluginName="Nir_Plugin_CursorBind.dll";
extern const char* _paramName1="margin";
extern int paramValue1=0;

// plugin functions
DWORD WINAPI hookWindow(LPVOID lpParam);
void initialize();

#endif // H_PLUGIN_INFO