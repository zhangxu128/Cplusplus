#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int fib1(int n)
{
	int last1 = 1;
	int last2 = 1;
	int temp;
	if (n == 1 || n == 2)
	{
		return 1;
	}
	if (n > 2)
	{
		for (int i = 2; i < n; i++)
		{
			temp = last1 + last2;
			last2 = last1;
			last1 = temp;
		}
		return last1;
	}
	return 0;
}

int fib2(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	return fib2(n - 1) + fib2(n - 2);
}

int factor(int n)
{
	if (n == 1)
	{
		return 1;
	}
	return n * factor(n - 1);
}

int main()
{
	//实现斐波那契数列
	int n = 0;
	scanf("%d",&n);
	printf("%d\n",fib1(n));
	printf("%d\n",fib2(n));
	printf("%d\n", factor(n));
	printf("%d\n",factor1(n));
	system("pause");
	return 0;
}