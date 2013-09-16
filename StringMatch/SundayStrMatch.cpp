#include "stdafx.h"

bool SundayStrMatch(const char *str, const char *pattern)
{
	if (NULL == str || NULL == pattern)
		return false;
	register int nstr = strlen(str);
	int npattern = strlen(pattern);
	printf("%d %d\n", nstr, npattern);
	char temp;
	int i, j, k;
	bool result = false;

	i = 0;
	j = 0;
	while (i < nstr && j < npattern)
	{
		if (str[i] == pattern[j])
		{
			i++;
			j++;
		}
		else
		{
			temp = 
		}
	}
	if (i < nstr)
		result = true;
//	printf("match failed.\n");
	return result;
}