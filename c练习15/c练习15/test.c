	#define _CRT_SECURE_NO_WARNINGS
	#include<stdio.h>
	#include<stdlib.h>

	int countone(int num)
	{
		int count = 0;
		for (int i = 0; i < 32; i++)
		{
			if ((num & 1) == 1)
			{
				count++;
			}
			num = num >> 1;
		}
		return count;
	}

	int main()
	{
		int num;
		scanf("%d",&num);
		printf("%d\n",countone(num));
		system("pause");
		return 0;
	}