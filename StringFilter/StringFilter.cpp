#include "stdafx.h"

/*
void stringFilter(const char *pInputStr, long lInputLen, char *pOutputStr)
{
	if (pInputStr == NULL)
	{
		pOutputStr == NULL;
		return;
	}
	int i,j;
	long lOutputLen = 0;
	for (i = 0; i < lInputLen; i++)
	{
		int flag = 0;
		for (j = 0; j < lOutputLen; j++)
		{
			if (pInputStr[i] == pOutputStr[j])
			{
				flag = 1;
				break;
			}
		}
		if (!flag)
			pOutputStr[lOutputLen++] = pInputStr[i];
	}
	pOutputStr[lOutputLen] = '\0';
}
*/

void stringFilter(const char *pInputStr, long lInputLen, char *pOutputStr)
{
	if (pInputStr == NULL)
	{
		pOutputStr = NULL;
		return;
	}

	long  charCount[30] = {0};
	const char *str = pInputStr;
	while (*str != '\0')
	{
		charCount[*str-'a']++;
		if (1 == charCount[*str-'a'])
		{
			*pOutputStr = *str;
			pOutputStr++;
		}
		str++;
	}
	*pOutputStr = '\0';
}