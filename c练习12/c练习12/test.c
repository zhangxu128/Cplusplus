#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int sum(int num, int bit)
{
	int sum = 0;
	int temp = 0;
	for (int i = 0; i < bit; i++)
	{
		temp = temp * 10 + num;
		sum += temp;
	}
	return sum;
}

int main()
{
	int num = 0;
	int bit = 0;
	scanf("%d%d", &num,&bit);
	int ret = sum(num, bit);
	printf("%d\n",ret);
	system("pause");
	return 0;
}