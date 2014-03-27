#include "../Nirvana_ext_import.h"
#pragma comment(lib, "../Build/bin/Nirvana_ext.lib")

// plugin info
volatile static HANDLE _selfHandle;

const char* _pluginName="Nir_Plugin_DelayReducer.dll";
const char* _paramName1="singlePlayerDelay";
const char* _paramName2="lanDelay";
const char* _paramName3="bnetDelay";
int paramValue1=10;
int paramValue2=50;
int paramValue3=100;

// plugin functions
void changeDelay(int singlePlayerDelay, int lanDelay, int bnetDelay);
void initialize();

