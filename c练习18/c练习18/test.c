#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
unsigned int reverse_bit(unsigned int value)
{
	unsigned int reverse=0;
	for (int i = 31; i >= 0; i--)
	{
		reverse += (value & 1) * (unsigned int)(pow(2 , i));
		value = value >> 1;
	}
	return reverse;
}
int main()
{
	unsigned int num;
	scanf("%d",&num);
	printf("%u\n", reverse_bit(num));
	system("pause");
	return 0;
}