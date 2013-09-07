#include "stdafx.h"
#include "StringFilter.h"

void arithmetic(const char *pInputStr, long lInputLen, char *pOutputStr)
{
	char op1[5], op[5], op2[5];

	sscanf(pInputStr, "%s %s %s", op1, op, op2);

	int data1 = atoi(op1);
	int data2 = atoi(op2);
	if (0 == strcmp(op, "+"))
	{
		int result = data1 + data2;
		itoa(result, pOutputStr, 10);
	}
	else if (0 == strcmp(op, "-"))
	{
		int result = data1 - data2;
		itoa(result, pOutputStr, 10);
	}
	else
	{
		itoa(0, pOutputStr, 10);
	}
}

/*
void arithmetic(const char *pInputStr, long lInputLen, char *pOutputStr)
{
	int i, cnt = 0, a, b, result;
	char ch[1] = {'0'};
	char op1[MAXCHAR], op[MAXCHAR], op2[MAXCHAR], buffer[4];
	for(i = 0; i < lInputLen; i++)
		if(pInputStr[i] == ' ')
			cnt++;
	
	if(cnt != 2) 
	{
		strcat(pOutputStr, ch);
		return;
	}
		
	sscanf(pInputStr, "%s %s %s", op1, op, op2);
	printf("%s %s %s\n", op1, op, op2);

	if(strlen(op) > 1 || (op[0] != '+' && op[0] != '-'))
	{
		strcat(pOutputStr, ch);
		return;
	}
	
	for(i = 0; i < strlen(op1); i++)
	{
		if(op1[i] < '0' || op1[i] > '9')
		{    
			strcat(pOutputStr, ch);
			return;
		}
	}
		
	
	for(i = 0; i < strlen(op2); i++)           //操作数2是否有其他字符
	{
		if(op2[i] < '0' || op2[i] > '9')
		{
			strcat(pOutputStr, ch);
			return;
		}
	}
	
	a = atoi(op1);
	b = atoi(op2);
	
	switch(op[0])
	{
		case '+':
			result = a + b;
			itoa(result, buffer, 10);
			strcat(pOutputStr, buffer);
			break;
		case '-':
			result = a - b;
			itoa(result, buffer, 10);
			strcat(pOutputStr, buffer);
			break;
		default:
			break;
	}
	
}
*/
