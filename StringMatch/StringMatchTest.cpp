// StringMatch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "StringMath.h"

void test1(const char *str, const char *pattern)
{
	bool result;
	result = KMPStrMatch(str, pattern);
	if (true == result)	
		printf("match success.\n");
	else 
		printf("match failed.\n");
}

int _tmain(int argc, _TCHAR* argv[])
{
//	test1("abababaababacb", "ababacb");
//	test1("abababaababacb", "");
	test1("abababaababacb", "aba");
//	test1("", "ababacb");
//	test1("", "");
	return 0;
}

