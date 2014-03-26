// IniFileHandler.h

#ifndef H_INI_FILE_HANDLER
#define H_INI_FILE_HANDLER
#include "Nirvana_ext.h"
#include "StringUtils.h"
#include <vector>
#include <fstream>
#include <sstream>

void readIni(std::vector<char*> &raceList, std::vector<Plugin*> &pluginList);

#endif // H_INI_FILE_HANDLER