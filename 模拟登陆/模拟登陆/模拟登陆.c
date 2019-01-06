#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char password[8] = {"12345678"};
	printf("请输入密码：\n");
	char str[20] = {0};
	scanf("%s", str);
	int count = 0;
	while(count<2)
	{ 
		if (! strcmp(str, password) == 0) 
		{
			printf("登陆成功\n");
			break;
		}
		else
		{
			printf("输入有误，请重新输入\n");
			scanf("%s", str);
		}
		count++;
	}
	if (count == 3)
	{
		printf("输入三次有误，密码锁定\n");
	}
	system("pause");
	return 0;
}