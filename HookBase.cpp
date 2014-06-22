#include "HookBase.h"

void inlineFuncHook::hook(UINT RVA_Offest, VOID* replaceFunc)
{
	m_pNewFunc = replaceFunc;
	DWORD dwOldProtect;
	m_pppFunc = (VOID***)((UINT)GetGameModuleHandle() + RVA_Offest);
	m_pOldFunc = **m_pppFunc;		// reads the old address
	if (VirtualProtect(*m_pppFunc, sizeof(*m_pppFunc), PAGE_EXECUTE_READWRITE, &dwOldProtect))
	{
		**m_pppFunc = m_pNewFunc;
		VirtualProtect(*m_pppFunc, sizeof(*m_pppFunc), dwOldProtect, &dwOldProtect);
	}
}

void inlineFuncHook::restore()
{
	if (m_pppFunc==NULL || m_pOldFunc==NULL) return;
	
	DWORD dwOldProtect;
	if (VirtualProtect(*m_pppFunc, sizeof(*m_pppFunc), PAGE_EXECUTE_READWRITE, &dwOldProtect))
	{
		**m_pppFunc = m_pOldFunc;
		VirtualProtect(*m_pppFunc, sizeof(*m_pppFunc), dwOldProtect, NULL);
	}
}