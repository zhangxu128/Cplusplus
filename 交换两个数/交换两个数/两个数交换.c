#include<stdio.h>
#include<stdlib.h>
//方式一：采用中间变量
int change1(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
	printf("方式一交换之后：a=%d b=%d\n",a,b);
	return 0;
}
//方式二，不要中间变量，会溢出
int change2(int a, int b)
{
	a = a + b;
	b = a - b;
	a = a - b;
	printf("方式二交换之后：a=%d b=%d\n", a, b);
	return 0;
}
//方式三，不用中间变量，不溢出
int change3(int a, int b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("方式三交换之后：a=%d b=%d\n", a, b);
	return 0;
}
int main()
{   
	int a = 5;
	int b = 4;
	printf("交换之前：a=%d b=%d\n", a, b);
	change1(5, 4);
	change2(5, 4);
	change3(5, 4);
	system("pause");
	return 0;
}