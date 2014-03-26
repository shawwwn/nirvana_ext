// StringUtils.h

#ifndef H_STR_UTILS
#define H_STR_UTILS
#include <string>


char* getLeftStr(char* line, int seperatorIndex);
char* getRightStr(char* line, int seperatorIndex);
int getCharIndex(char* line, int charater);
bool isBlank(char* line);
char* trim(char* s);
char* concatenate(char* first, char* last);

#endif // H_STR_UTILS