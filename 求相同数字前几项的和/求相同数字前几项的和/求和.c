#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num = 0;
	int count = 0;
	int sum = 0;
	int tmp = 0;
	scanf("%d%d", &num, &count);
	int i = 0;
	for (i = 0; i < count; i++)
	{
		tmp = tmp * 10 + num;
		sum += tmp;
	}
	printf("%d\n", sum);
	system("pause");
	return 0;
}
