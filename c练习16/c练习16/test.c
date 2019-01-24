#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void func(int num)
{
	int num1 = num;
	printf("奇数序列为：\n");
	for (int i = 0; i < 32; i += 2)
	{
		printf("%d",(num&1));
		num = num >> 2;
	}
	printf("\n");
	num1 = num1 >> 1;
	printf("偶数序列为：\n");
	for (int i = 1; i < 32; i += 2)
	{
		printf("%d", (num1 & 1));
		num1 = num1 >> 2;
	}
	printf("\n");
}

int main()
{
	int num;
	scanf("%d",&num);
	func(num);
	system("pause");
	return 0;
}