// IniFileHandler.h

#ifndef H_INI_FILE_HANDLER
#define H_INI_FILE_HANDLER
#include "Nirvana_ext.h"
#include "StringUtils.h"
#include <vector>
#include <fstream>             // std::ifstream
#include <sstream>             // std::istringstream

void readIni(std::vector<char*> &raceList, std::vector<Plugin*> &pluginList);

#endif // H_INI_FILE_HANDLER