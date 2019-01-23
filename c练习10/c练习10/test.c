#include<stdio.h>
#include<stdlib.h>
int main()
{
	for (int i = 1; i <= 13; i++)
	{
		int j = i;
		if (j % 2 != 0)
		{
			while (j != 0)
			{
				printf("*");
				j--;
			}
			printf("\n");
		}
		else
		{
			printf("\n");
		}
	}
	printf("\n");
	for (int i = 11; i >= 1; i--)
	{
		int j = i;
		if (j % 2 != 0)
		{
			while (j != 0)
			{
				printf("*");
				j--;
			}
			printf("\n");
		}
		else
		{
			printf("\n");
		}
	}
	system("pause");
	return 0;
}