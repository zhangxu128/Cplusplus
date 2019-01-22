#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a[] = { 1,2,3 };
	int b[] = { 4,5,6 };
	for (int i = 0; i < 3; i++)
	{
		int temp;
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
	for (int i = 0; i < 3; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	for (int i = 0; i < 3; i++)
	{
		printf("%d ", b[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}