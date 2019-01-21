#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void exchange1(int num1, int num2)
{
	int temp;
	temp = num1;
	num1 = num2;
	num2 = temp;
	printf("num1=%d num2=%d\n",num1,num2);
}

void exchange2(int num1, int num2)
{
	num1 = num1 + num2;
	num2 = num1 - num2;
	num1 = num1 - num2;
	printf("num1=%d num2=%d\n", num1, num2);
}

void exchange3(int num1, int num2)
{
	num1 = num1 ^ num2;
	num2 = num1 ^ num2;
	num1 = num1 ^ num2;
	printf("num1=%d num2=%d\n", num1, num2);
}

int main()
{
	//交换两个变量的值
	int num1 = 0;
	int num2 = 0;
	scanf("%d%d",&num1,&num2);
	printf("交换之前num1=%d num2=%d\n",num1,num2);
	printf("交换之后\n");
	exchange1(num1, num2);
	exchange2(num1, num2);
	exchange3(num1, num2);
	system("pause");
	return 0;
}