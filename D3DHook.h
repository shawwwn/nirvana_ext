// Nirvana_ext_import.h
#pragma once

#include "Nirvana_ext.h"
#include "HookBase.h"

#define RVA_Direct3DCreate8	0x0052CFBB		// Actually, it is the rva for GetProcAddress of Direct3DCreate8

#define DX_DLL_NAME "Nir_Plugin_RenderCraft.dll"

extern inlineFuncHook d3dHook;

void hookDirect3DCreate8();