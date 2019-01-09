#include<stdio.h>
#include<stdlib.h>
int print(int n)
{
	for (int i = 1; i <= n; i++)
	{
		printf("*");
	}
	return 0;
}
int main()
{
	for (int i = 1; i <= 7; i++)
	{
		print(2*i-1);
		printf("\n");
	}
	for (int i = 6; i >0; i--)
	{
		print(2 * i - 1);
		printf("\n");
	}
	system("pause");
	return 0;
}