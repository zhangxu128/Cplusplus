#include<stdio.h>
#include<stdlib.h>

int main()
{
	int num[] = { 23,23,43,54,12,43,32,545,322,134 };
	int max = num[0];
	for (int i = 0; i < 10; i++)
	{
		if (num[i] > max)
		{
			max = num[i];
		}
	}
	printf("max=%d\n", max);
	system("pause");
	return 0;
}