#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int get_line(unsigned int num)
{
	unsigned int one = 1;
	printf("��������������Ϊ��\n");
	for (unsigned int i = 1; i <= 30; i+=2)
	{
		printf("%d", ((num << i)&one));
	}
	printf("\n");
	printf("������ż������Ϊ��\n");
	for (unsigned int i = 0; i <= 31; i += 2)
	{
		printf("%d", ((num << i)&one));
	}
	printf("\n");
	return 0;
}
int main()
{
	unsigned int num = 0;
	scanf("%d", &num);
	get_line(num);
	system("pause");
	return 0;
}