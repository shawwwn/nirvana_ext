#include "../Nirvana_ext_export.h"
#pragma comment(lib, "../Build/bin/Nirvana_ext.lib")

// plugin info
volatile static HANDLE _selfHandle;

const char* _pluginName="Nir_Plugin_Manabar.dll";
const char* _paramName1="thickness";
double paramValue1=1.00;

// plugin functions
#pragma once
BOOL WINAPI ShowManaBar();
void initialize();

