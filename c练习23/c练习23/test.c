#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int string_move(char *msg, char *substring)
{
	int len = strlen(msg);
	char *tmp = (char*)malloc(2 * len + 1);  //����2������ռ�
	if (len == strlen(substring))  //��֤Ҫ�Ƚϵ������ַ���������ͬ
	{
		strcpy(tmp, msg);  //ԭ�����ַ����������¿ռ���
		strcat(tmp, msg);  //�ַ�����ƴ�ӣ�ʵ�ָ���
		if (strstr(tmp, substring) != NULL)
		{
			return 1;
		}
	}
	free(tmp);  //�ͷ�������¿ռ�
	return 0;
}

int main()
{
	/*�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
		���磺����s1 = AABCD��s2 = BCDAA������1������s1 = abcd��s2 = ACBD������0.

		AABCD����һ���ַ��õ�ABCDA
		AABCD���������ַ��õ�BCDAA

		AABCD����һ���ַ��õ�DAABC*/
	char arr1[] = "abcdef";
	char arr2[6];
	scanf("%s",&arr2);
	if (string_move(arr1, arr2)==1)
	{
		printf("����ת֮����ַ���\n");
	}
	else
	{
		printf("������ת֮����ַ���\n");
	}
	system("pause");
	return 0;
}