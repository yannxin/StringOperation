#include "stdafx.h"
#include "StringFilter.h"

void DivideString(const char *pInputStr,long lInputLen, char *pOutputStr)
{
	const char *str = pInputStr;
	while (*str == ' ')
		str++;

	while (*str)
	{
		if (*str == ' ')
		{
			*pOutputStr++ = ',';
			while (*str == ' ')
				str++;
		}
		else
		{
			*pOutputStr++ = *str++;
		}
	}
	if (*(pOutputStr-1) != ',')
	{
		*pOutputStr++ = ',';
	}
	*pOutputStr = '\0';
}