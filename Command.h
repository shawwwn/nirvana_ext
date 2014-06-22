#pragma once

#define WIN32_LEAN_AND_MEAN 
#include <Windows.h>
#include <vector>
#include "HookUtils.h"
#include "argcargv.h"		// parse process command line


#define OPEN_ARCHIVE_RVA 0x006EB57C 
#define START_PRIORITY 0x10
typedef bool (CALLBACK* SFileOpenArchive)(const char* szMpqName, DWORD dwPriority, DWORD dwFlags, HANDLE* phMPQ);


bool loadMpqEx(const char* mpqPath, DWORD priority, HANDLE* hMpq);
void readCommands(std::vector<char*> &raceList);