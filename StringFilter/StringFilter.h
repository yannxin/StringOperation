

#pragma once

#define MAXCHAR 256
void stringFilter(const char *pInputStr, long lInputLen, char *pOutputStr);
void stringZip(const char *pInputStr, long lInputLen, char *pOutputStr);
void arithmetic(const char *pInputStr, long lInputLen, char *pOutputStr);
void DivideString(const char *pInputStr,long lInputLen, char *pOutputStr);
int DeleteSubStrOnce(char *sourceStr, const char *subStr);
int DeleteSubStr(const char *str, const char *subStr, char *resultStr);
