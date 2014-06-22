#include "Command.h"
#include <stdio.h>

bool endWith(const char* cstr, const char* postfix)
{
	UINT startPos = strlen(cstr)-strlen(postfix);
	if (startPos<=0)
		return false;
	return strcmp(cstr+startPos, postfix)==0 ? true: false;
}

bool loadMpqEx(const char* mpqPath, DWORD priority, HANDLE* hMpq)
{
	SFileOpenArchive func = (SFileOpenArchive)((DWORD)GetGameModuleHandle() + OPEN_ARCHIVE_RVA);
	return func(mpqPath, priority, 0, hMpq);
}

void readCommands(std::vector<char*> &raceList)
{
	UINT priority = START_PRIORITY;
	UINT argc = _ConvertCommandLineToArgcArgv();
	for (UINT i=0; i<argc; i++)
	{
		// "-mpq" commond, load extra mpqs
		if (strcmp(_ppszArgv[i], "-mpq")==0)
		{
			i++;
			while (i<argc && endWith( _ppszArgv[i], ".mpq"))
			{
				HANDLE hMPQ;
				loadMpqEx(_ppszArgv[i], priority, &hMPQ);
				priority++;
				i++;
			}
		}

		// "-ini" command, read new commands
		if (strcmp(_ppszArgv[i], "-race")==0)
		{
			i++;
			// make a copy of the argument string
			int length = strlen(_ppszArgv[i]);
			char* race_str = new char[strlen(_ppszArgv[i])];
			strcpy(race_str, _ppszArgv[i]);

			// clear the old race list
			raceList.clear();		// TODO: Clean up the memory leak

			// construct new race list
			char* pch;
			pch = strtok (race_str," ,");
			while (pch != NULL)
			{
				char* race_name = new char[strlen(pch)];
				strcpy(race_name, pch);
				raceList.push_back(race_name);
				pch = strtok (NULL, " ,");
			}

		}
	}
}