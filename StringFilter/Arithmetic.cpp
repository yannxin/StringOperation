#include "stdafx.h"
#include "StringFilter.h"
/*
void arithmetic(const char *pInputStr, long lInputLen, char *pOutputStr)
{
	char *str[3];
	str[0] = new char[5];
	str[1] = new char[5];
	str[2] = new char[5];

	sscanf(pInputStr, "%s %s %s", str[0], str[1], str[2]);

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
*/

void arithmetic(const char *pInputStr, long lInputLen, char *pOutputStr)
{
    int i, cnt = 0, a, b, result;
    char ch[1] = {'0'};
    char op1[MAXCHAR], op[MAXCHAR], op2[MAXCHAR], buffer[4];
    for(i = 0; i < lInputLen; i++)
        if(pInputStr[i] == ' ')
            cnt++;
    
    if(cnt != 2)      //�ո���������2
    {
        strcat(pOutputStr, ch);
        return;
    }
        
    sscanf(pInputStr, "%s %s %s", op1, op, op2);
	printf("%s %s %s\n", op1, op, op2);

    if(strlen(op) > 1 || (op[0] != '+' && op[0] != '-')) // �������ж��
    {
        strcat(pOutputStr, ch);
        return;
    }
    
    for(i = 0; i < strlen(op1); i++)             //������1�Ƿ��������ַ�
    {
        if(op1[i] < '0' || op1[i] > '9')
        {    
            strcat(pOutputStr, ch);
            return;
        }
    }
        
    
    for(i = 0; i < strlen(op2); i++)           //������2�Ƿ��������ַ�
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
			printf("%d\n", result);
            itoa(result, buffer, 10);
            strcat(pOutputStr, buffer);
			printf("%s\n", pOutputStr);
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
