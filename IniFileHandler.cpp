// IniFileHandler.cpp

#include "IniFileHandler.h"
#include <iostream>
using namespace std;

void readIni(std::vector<char*> &raceList, std::vector<Plugin> &pluginList)
{
	// read the whole file to memory
	//std::ifstream ini("Nirvana.ini", std::ios::in);
	// TODO: Restore the last line, remove the next line.
	std::ifstream ini_fs("D:\\Program Files\\VC6cn\\MyProjects\\Nirvana_ext\\Build\\bin\\Nirvana.ini", std::ios::in || std::ios::binary);
	if (!ini_fs)
		return;

    ini_fs.seekg(0, std::ios::end);
    int ini_length = ini_fs.tellg();
    ini_fs.seekg(0, std::ios::beg);
	char* ini_buffer = new char[ini_length];
	memset(ini_buffer, 0, ini_length); // batch set zero
	ini_fs.read(ini_buffer, ini_length);
	ini_fs.close();
	if (!ini_buffer)
		return;
	istringstream ini_ss(ini_buffer, strlen(ini_buffer));
	delete[] ini_buffer;	// no longer needed


	// iterate through each line
	ini_ss.seekg(0, std::ios::beg);
	while(!ini_ss.eof())
	{
		//char* buffer = new char[256];
		char buffer[256];
		ini_ss.getline(&buffer[0], 256);
		char* line=trim(buffer);	// TODO: Add trimComments()

		// return if line is a comment 
		if (strncmp (line, "//", 2) == 0)
			continue;

		// populate race list
		bool hitRaceEnd=false;
		if (strcmp(line, "#Race Start")==0)
		{
			while(!ini_ss.eof())
			{
				char buffer2[32];
				ini_ss.getline(&buffer2[0], 32);
				line=trim(buffer2);
				
				if (strcmp(line, "#Race End")==0)
				{
					hitRaceEnd=true;
					break;
				}
				char* raceName=new char[strlen(line)];	// Allocs a new string, in case the temp variable got recycled.
				strcpy(raceName, line);
				raceList.push_back(raceName);
			}
			if (ini_ss.eof())
				return;
		}
		if (hitRaceEnd)
			continue;

		// populate pluginInfo
		Plugin plg;

		cout << line << endl;


	}
	ini_ss.str(""); // clear the stream
}