#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int reserve(int x)
{
	int y = 0;
	long sum = 0;
	while (x != 0)
	{
		y = x % 10;
		sum = sum * 10 + y;
		x = x / 10;
	}
	if (sum < INT_MAX && sum > INT_MIN) 
	{
		return 0;
	}
	return sum;
}
int main()
{
	int x=0;
	scanf("%d",&x);
	printf("%d",reserve(x));
	system("pause");
	return 0;
}