#include "StdAfx.h"

void add (const char *num1, const char *num2, char *result);
void myAdd(const char *num1, const char *num2, char *result);
void mySubstract(const char *num1, const char *num2, char *result);
int isBigger(const char *num1, const char *num2);
void convertStr(char *str);

int main()
{
	const char num1[] = "-50000";
	const char num2[] = "-58888";	


	char sum[100] = {0};

	add(num1,num2,sum);
	printf("\nsum%s\n",sum);
	return 0;
}
void add(const char *num1, const char *num2, char *result)
{
	if(num1 == NULL)
		strcpy(result,num2);
	if(num2 == NULL)
		strcpy(result,num1);
	printf("num1:%s\nnum2:%s\n",num1,num2);
	bool minus1 = (num1[0] == '-')?  true : false;
	bool minus2 = (num2[0] == '-')?  true : false;

	if (minus1 && minus2)
	{
		result[0] = '-';
		myAdd(num1+1,num2 + 1,result + 1);
	}

	 if (minus1 && !minus2)
	{ 
		if (strcmp(num1 + 1, num2) == 0)
		{
			result[0] = '0';
			result[1] = '\0';
		}
		else if (isBigger(num1+1,num2) == 1)
		{
			result[0] = '-';
			mySubstract(num1 + 1,num2,result + 1);
		}
		else if(isBigger(num1+1,num2) == 0)
		{
			mySubstract(num2,num1 + 1,result);
		}
	}
	  if(!minus1 && minus2)
	{
		if (strcmp(num1, num2 + 1) == 0)
		{
			result[0] = '0';
			result[1] = '\0';
		}
		else if (isBigger(num2+1,num1) == 1)
		{
			result[0] = '-';
			mySubstract(num2 + 1,num1,result + 1);
		}
		else if(isBigger(num2+1,num1) == 0)
		{
			mySubstract(num1,num2 + 1,result);
		}
	}
	if(!minus1 && !minus2)
	{
		myAdd(num1, num2,result);
	}
}

void myAdd(const char *num1, const char *num2, char *result)
{
	int i = strlen(num1) - 1;
	int  j = strlen(num2) - 1;
	int  k  = 0;
	int flag = 0;
	int bitSum = 0;

	while (i >= 0 && j >= 0)
	{
		bitSum = num1[i] - '0' + num2[j] - '0' + flag;
		if (bitSum >= 10)
		{
			result[k] = bitSum - 10 + '0';
			flag = 1;
			k++;
		}
		else
		{
			result[k] = bitSum + '0';
			flag = 0;
			k++;
		}
		i--; 
		j--;
	}
	if(i < 0 && j < 0)
	{
		if (flag == 1)
		{
			result[k] = 1 + '0';
			result[k + 1] = '\0';
		}
	}
	else if(i < 0)
	{
		while (j >= 0)
		{
			bitSum = num2[j] - '0' + flag;
			if (bitSum >= 10)
			{
				result[k] = bitSum - 10 + '0';
				flag = 1;
				k++;
			}
			else
			{
				result[k] = bitSum + '0';
				flag = 0;
				k++;
			}
			j--;
		}
		if(flag == 1)
		{
			result[k] = flag + '0';
			result[k+1] = '\0';
		}
		else
			result[k] = '\0';
	}
	else if(j < 0)
	{
		while (i >= 0)
		{
			bitSum = num2[i] - '0' + flag;
			if (bitSum >= 10)
			{
				result[k] = bitSum - 10 - '0';
				flag = 1;
				k++;
			}
			else
			{
				result[k] = bitSum - '0';
				k++;
			}
			i--;
		}
		if(flag == 1)
		{
			result[k] = flag + '0';
			result[k  + 1] = '\0'; 
		}
		else
		{ 
			result[k] = '\0';
		}
	}
	convertStr(result);
}

int isBigger(const char *num1, const char *num2)
{
	int num1Len = strlen(num1);
	int num2Len = strlen(num2);
	if (num1Len < num2Len)
	{
		return 0;
	}
	else if (num2Len < num1Len)
	{
		return 1;
	}
	else
	{
		int bitDiff = 0;
		int flag = 0;
		int i = num1Len - 1;

		while (i >= 0)
		{
			bitDiff = num1[i]  - num2[i] - flag;
			if (bitDiff < 0)
			{
				flag = 1;
			}
			else
				flag = 0;
		}
		if(flag == 0)
			return 1;
		else
			return 0;
	}

}
void mySubstract(const char *num1, const char *num2, char *result)
{
	int i = strlen(num1) - 1;
	int j = strlen(num2) - 1;
	int  k = 0;
	int bitDiff = 0;
	int flag = 0;
	while (i  >= 0 && j >= 0)
	{
		bitDiff = num1[i]   - num2[j] - flag;
		if (bitDiff < 0)
		{
			result[k] = bitDiff + 10 + '0';
			k++;
			flag = 1;
		}
		else
		{
			result[k] = bitDiff + '0';
			k++;
			flag = 0;
		}
		i--;
		j--;
	}
	if (i >=0)
	{
		while (i>=0)
		{
			bitDiff = num1[i] - '0'  - flag;
			if (bitDiff < 0)
			{
				result[k] = bitDiff + 10 + '0';
				k++;
				flag = 1;
			}
			else
			{
				result[k] = bitDiff + '0';
				k++;
				flag = 0;
			}
		}
		i--;
	}
	while (result[k - 1] == 0 && k != 1)
		k--;
	result[k] = '\0';
	convertStr(result);
}
void convertStr(char *str)
{
	char *p = str;
	char *q = str + strlen(str) - 1;
	while (p < q)
	{
		char temp = *p;
		*p = *q;
		*q = temp;
		p++;
		q--;
	}
}

