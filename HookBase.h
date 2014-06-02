#pragma once

#define WIN32_LEAN_AND_MEAN 
#include <Windows.h>

#define GAME_DLL "Nirvana.dll"

HMODULE GetGameModuleHandle();
HMODULE GetExeModuleHandle();

class inlineFuncHook
{
public:
	inlineFuncHook(): m_pppFunc(NULL), m_pOldFunc(NULL), m_pNewFunc(NULL) {};
	~inlineFuncHook() {};
	void hook(UINT RVA_Offest, VOID* replaceFunc);
	void restore();
	VOID* getOldFunctionPtr() { return m_pOldFunc; }
	VOID* getNewFunctionPtr() { return m_pNewFunc; }
	UINT getHookAddress() { return (UINT)m_pppFunc; }
protected:
	VOID*** m_pppFunc;
	VOID* m_pOldFunc;
	VOID* m_pNewFunc;
};