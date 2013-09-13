#include "stdafx.h"

void SelfStrMatch(const char *pattern, int pre[])
{
	if (NULL == pattern)
		return;
	register int npattern = strlen(pattern);
	pre[0] = -1;
	int i, j = -1;
	for (i = 1; i < npattern; i++)
	{
		while (j >= 0 && pattern[j+1] != pattern[i])
			j = pre[j];

		if (pattern[j+1] == pattern[i])
			j++;
		pre[i] = j;
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

	j = -1;
	for (i = 0; i < nstr; i++)
	{
		while (j >= 0 && pattern[j+1] != str[i])
			j = pre[j];
		if (pattern[j+1] == str[i])
			j++;
		if (j == npattern - 1)
		{
//			printf("match success.\n");
			printf("match position: %d\n", i-j);
			result = true;
			j = pre[j];
		}
	}
	delete []pre;
//	printf("match failed.\n");
	return result;
}