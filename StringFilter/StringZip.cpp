#include "stdafx.h"
/*
void stringZip(const char *pInputStr, long lInputLen, char *pOutputStr)
{
	if (pInputStr == NULL)
	{
		pOutputStr = NULL;
		return;
	}
	int i = 0;
	while (i < lInputLen)
	{
		int j = i;
		while (pInputStr[j] == pInputStr[i])
		{
			j++;
		}
	
		if (j-i > 1)
		{
			char *num = (char *)malloc(sizeof(char)*64);
			itoa(j-i, num, 10);
			while (*num != '\0')
			{
				*pOutputStr++ = *num++;
			}
		}
		*pOutputStr++ = pInputStr[i];
		i = j;
	}
	*pOutputStr = '\0';
}
*/

void stringZip(const char *pInputStr, long lInputLen, char *pOutputStr)
{
	if (pInputStr == NULL)
	{
		pOutputStr = NULL;
		return;
	}
	const char *first = pInputStr;
	const char *last = pInputStr;

	while (*last != '\0')
	{
		int count = 0;
		while (*first == *last)
		{
			count++;
			last++;
		}
	
		if (count > 1)
		{
			char *num = (char *)malloc(sizeof(char)*64);
			itoa(count, num, 10);
			while (*num != '\0')
			{
				*pOutputStr++ = *num++;
			}
//			free (num);
		}
		*pOutputStr++ = *first;
		first = last;
	}
	*pOutputStr = '\0';
}