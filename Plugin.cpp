// Plugin.cpp
#include "Nirvana_ext.h"
#include "Nirvana_ext_export.h"

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
	parameterSize = 0;
	pluginName=new char[strlen(name)];
	strcpy(pluginName, name);
}

Plugin* getPluginInfo(const char* pluginName)
{
	int size=PluginList.size();
	if (size==0)
		return NULL;

	// TODO: Use table instead of vector for faster query
	for (int i=0; i<size; i++)
	{
		Plugin* plg_ptr=PluginList[i];
		if (strcmp(plg_ptr->pluginName, pluginName)==0)
			return plg_ptr;
	}
	return NULL;
}
