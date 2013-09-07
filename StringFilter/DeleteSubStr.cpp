#include "stdafx.h"
#include "StringFilter.h"

int DeleteSubStrOnce(char *sourceStr, const char *subStr)
{
	int isSubStr = 1;

	int sourceStrLen = strlen(sourceStr);
	int subStrLen = strlen(subStr);
	int end = sourceStrLen - subStrLen;

	int i = 0;
	while (i <= end)
	{
		int j = 0;
		isSubStr = 1;
		while (j < subStrLen)
		{
			if (sourceStr[i++] != subStr[j++])
			{
				isSubStr = 0;
				break;
			}
		}
		if (isSubStr)
		{
			strcpy(sourceStr+i-subStrLen, sourceStr+i);
		}
	}
	return isSubStr;
}

int DeleteSubStr(const char *str, const char *subStr, char *resultStr)
{
	int size = strlen(str);
	char *sourceStr = new char[size+1];
	strcpy(sourceStr, str);

	int cnt = 0;
	while (1)
	{
		if (DeleteSubStrOnce(sourceStr, subStr))
		{
			cnt++;
		}
		else
		{
			resultStr = sourceStr;
			break;
		}
	}
	return cnt;
}