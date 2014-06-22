#pragma once

#define WIN32_LEAN_AND_MEAN 
#include <Windows.h>
#define GAME_DLL "Nirvana.dll"

HMODULE GetGameModuleHandle();
HMODULE GetExeModuleHandle();

void JmpPatch(void* pDest, void* pSrc, int nNops);
DWORD getFuncPtr(DWORD address);
