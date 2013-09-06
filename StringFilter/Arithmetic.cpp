#include "stdafx.h"

void arithmetic(const char *pInputStr, long lInputLen, char *pOutputStr)
{
	char *str[3];
	str[0] = new char[5];
	str[1] = new char[5];
	str[2] = new char[5];

	int k = 0;
	while (*pInputStr != '\0')
	{
		if (*pInputStr == ' ')
		{
			*str[k] = '\0';
			k++;
			pInputStr++;
		}
		else
		{
			*str[k]++ = *pInputStr++;
		}
	}
	*str[k] = '\0';

	printf("%s %s %s\n", str[0], str[1], str[2]);

	if (0 == strcmp(str[1], "+"))
	{
		int data1 = atoi(str[0]);
		int data2 = atoi(str[2]);
		int result = data1 + data2;
		itoa(result, pOutputStr, 10);

	}
	else if (0 == strcmp(str[1], "-"))
	{
		int data1 = atoi(str[0]);
		int data2 = atoi(str[2]);
		int result = data1 - data2;
		if (result < 0)
		{
			*pOutputStr++ = '-';
		}
		itoa(abs(result), pOutputStr, 10);
	}
	else
	{
		itoa(0, pOutputStr, 10);
	}
}