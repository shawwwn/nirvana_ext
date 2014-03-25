// Nir_Plugin_DelayReducer.cpp

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#define ADDRESS unsigned int

#pragma comment(linker,"/entry:DllMain")
#pragma comment(linker, "/MERGE:.rdata=.text") 
#pragma comment(linker, "/MERGE:.data=.text") 
#pragma comment(linker, "/MERGE:code=.text") 
#pragma comment(linker,"/SECTION:.text,RWE")
#pragma optimize("gsy", on)

volatile static HANDLE _selfHandle;

void initialize()
{
	ADDRESS gameBaseAddress = (ADDRESS)GetModuleHandle("nirvana.dll");
	LPVOID localAddress = (LPVOID*)(gameBaseAddress+0x660F01);      // 0x64 (100ms)
	LPVOID lanAddress = (LPVOID*)(gameBaseAddress+0x661A91);        // 0x64 (100ms)
	LPVOID netAddress = (LPVOID*)(gameBaseAddress+0x65DE41);        // 0x0FA (250ms)

	DWORD dwOldProtect;
	VirtualProtect(localAddress, sizeof(DWORD), PAGE_EXECUTE_READWRITE, &dwOldProtect);
	*(DWORD*)localAddress = 50; // 35ms

	VirtualProtect(lanAddress, sizeof(DWORD), PAGE_EXECUTE_READWRITE, &dwOldProtect);
	*(DWORD*)lanAddress = 50; // 35ms

	VirtualProtect(netAddress, sizeof(DWORD), PAGE_EXECUTE_READWRITE, &dwOldProtect);
	*(DWORD*)netAddress = 100; // 100ms
}

BOOL APIENTRY DllMain(HANDLE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	_selfHandle=hModule;
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		initialize();
		break;
	case DLL_PROCESS_DETACH:
		break;
	default:
		break;
	}
    return TRUE;
}

