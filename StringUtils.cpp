// StringUtils.cpp

#include "StringUtils.h"

// this will alloc a new string
char* getLeftStr(char* line, int seperatorIndex)
{
	if (seperatorIndex == 0)
		return NULL;

	int length = seperatorIndex;
	char* leftStr = new char[length+1];
	strncpy(leftStr, line, length);
	leftStr[length]='\0';
	return leftStr;
}

// this will alloc a new string
char* getRightStr(char* line, int seperatorIndex)
{
	char* nextCharPos = line+seperatorIndex+1;
	if (*nextCharPos == '\0')
		return NULL;

	int length = strlen(line)-(seperatorIndex+1);
	char* rightStr = new char[length+1];
	strncpy(rightStr, nextCharPos, length);
	rightStr[length]='\0';
	return rightStr;
}

int getCharIndex(char* line, int charater)
{
	char* pch=strchr(line, '=');
	if (pch==NULL)
		return -1;
	return pch-line;
}

bool isBlank(char* line)
{
	int len;
	int i;
	len = strlen(line);
	for (i=0; i<len; i++)
	{
		if (isspace(line[i]) == false)
			return false;
	}
	return true;
}

char* trim(char* s)
{
    char *end = s + strlen(s)-1;
    while(*s && isspace(*s))
        *s++ = 0;
    while(isspace(*end))
        *end-- = 0;
    return s;
}

char* concatenate(char* first, char* last)
{
	size_t size = strlen(first) + strlen(last) + 1;
	char* result = new char[size];
	strcpy(result, first);
	strcat(result, last);
	return result;
}
