#include "stdafx.h"

void SelfStrMatch(const char *pattern, int pre[])
{
	if (NULL == pattern)
		return;
	register int npattern = strlen(pattern);
	pre[0] = 0;
	int i, j = 0;
	for (i = 1; i < npattern; i++)
	{
		while (j > 0 && pattern[j] != pattern[i])
			j = pre[j];

		pre[i] = j;
		if (pattern[j] == pattern[i])
			j++;
	}
}

bool KMPStrMatch(const char *str, const char *pattern)
{
	if (NULL == str || NULL == pattern)
		return false;
	int nstr = strlen(str);
	int npattern = strlen(pattern);
	printf("%d %d\n", nstr, npattern);
	int *pre = new int[npattern];
	SelfStrMatch(pattern, pre);
	int i, j;
	bool result = false;
	for (i = 0; i < npattern; i++)
	{
		printf("%d ", pre[i]);
	}
	printf("\n");

	j = 0;
	for (i = 0; i < nstr; i++)
	{
		while (j > 0 && str[i] != pattern[j])
			j = pre[j];
		if (pattern[j] == str[i])
			j++;
		if (j == npattern)
		{
//			printf("match success.\n");
			printf("match position: %d\n", i-j+1);
			result = true;
			j = pre[j-1];
		}
	}
	delete []pre;
//	printf("match failed.\n");
	return result;
}