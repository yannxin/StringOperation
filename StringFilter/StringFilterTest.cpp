// StringFilter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "StringFilter.h"
#include "StringAdd.h"

void test1(const char *input, const char *exceptOutput)
{
//	char *input = "abacadae";
	char *output = (char *)malloc(sizeof(char)*(strlen(input)+1));
	stringFilter(input, strlen(input), output);
//	printf("%s\n", output);
	if (0 == strcmp(output, exceptOutput))
		printf("string filter is success.\n");
	else 
		printf("string filter failed.\n");
}

void test2(const char *input, const char *exceptOutput)
{
//	char *input = "abacadae";
	char *output = (char *)malloc(sizeof(char)*(strlen(input)+1));
	stringZip(input, strlen(input), output);
//	printf("%s\n", output);
	if (0 == strcmp(output, exceptOutput))
		printf("string zip is success.\n");
	else 
		printf("string zip failed.\n");
}

void test3(const char *input, const char *exceptOutput)
{
//	char *input = "abacadae";

	char *output = (char *)malloc(sizeof(char)*(strlen(input)+1));
	memset(output, 0, strlen(output));
	arithmetic(input, strlen(input), output);
//	printf("%s\n", output);
	if (0 == strcmp(output, exceptOutput))
		printf("arithmetic is success.\n");
	else 
		printf("arithmetic failed.\n");
}

void test4(const char *input, const char *exceptOutput)
{
//	char *input = "abacadae";

	char *output = (char *)malloc(sizeof(char)*(strlen(input)+1));
	memset(output, '\0', strlen(output));
	DivideString(input, strlen(input), output);
//	printf("%s\n", output);
	if (0 == strcmp(output, exceptOutput))
		printf("divide string is success.\n");
	else 
		printf("divide string failed.\n");
}

void test5(const char *str, const char *subStr, const char *exceptOutput)
{
//	char *input = "abacadae";

	char *output = (char *)malloc(sizeof(char)*(strlen(str)+1));
	memset(output, '0', strlen(output));
	int result = DeleteSubStr(str, subStr, output);

//	printf("%s\n", output);
	printf("result = %d\n", result);
	if (0 == strcmp(output, exceptOutput))
		printf("divide string is success.\n");
	else 
		printf("divide string failed.\n");
}

int _tmain(int argc, _TCHAR* argv[])
{

	test1("abacadae", "abcde");
	test2("xxyzzzzzzzzzzz", "2xy11z");
	test3("3 -- 4", "0");
	test4(" ab cd efg   hi", "ab,cd,efg,hi,");
	test5("abcde123abcd123", "123", "abcdeabcd");
	return 0;
}

