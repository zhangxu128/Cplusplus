#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void fun(int a, int b)
{
	int num1 = a;
	int num2 = b;
	int c;
	while (a%b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	printf("��С������Ϊ��%d,���Լ��Ϊ��%d\n", num1*num2 / b, b);
}

int main()
{
	int a, b;
	scanf("%d%d",&a,&b);
	fun(a, b);
	system("pause");
	return 0;
}