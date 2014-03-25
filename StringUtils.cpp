// StringUtils.cpp

#include "StringUtils.h"

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
