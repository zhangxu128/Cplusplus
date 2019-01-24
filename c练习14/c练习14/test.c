#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int digtalsum(int num)
{
	if (num < 10)
	{
		return num;
	}
	return num % 10 + digtalsum(num / 10);
}

int main()
{
	int num;
	scanf("%d",&num);
	printf("%d\n",digtalsum(num));
	system("pause");
	return 0;
}