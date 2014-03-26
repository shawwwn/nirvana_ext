// Plugin.cpp
#include "Nirvana_ext.h"

PluginParameter::PluginParameter(char* name, char* value, bool allocNew)
{
	if (allocNew)
	{
		int len=strlen(name);
		paramName=new char[len+1];
		strcpy(paramName, name);
		paramName[len]='\0';

		len=strlen(name);
		paramValue=new char[len+1];
		strcpy(paramValue, value);
		paramValue[len]='\0';
	}
	else
	{
		paramName=name;
		paramValue=value;
	}
}

Plugin::Plugin(char* name)
{
	pluginName=new char[strlen(name)];
	strcpy(pluginName, name);
}
std::vector<char*> RaceList;
std::vector<Plugin*> PluginList;