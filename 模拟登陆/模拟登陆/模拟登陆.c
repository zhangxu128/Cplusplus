#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char password[8] = {"12345678"};
	printf("���������룺\n");
	char str[20] = {0};
	scanf("%s", str);
	int count = 0;
	while(count<2)
	{ 
		if (! strcmp(str, password) == 0) 
		{
			printf("��½�ɹ�\n");
			break;
		}
		else
		{
			printf("������������������\n");
			scanf("%s", str);
		}
		count++;
	}
	if (count == 3)
	{
		printf("��������������������\n");
	}
	system("pause");
	return 0;
}