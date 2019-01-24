	#define _CRT_SECURE_NO_WARNINGS
	#include<stdio.h>
	#include<stdlib.h>
	int diff_bit(int m,int n)
	{
		int count = 0;
		for (int i = 0; i < 32; i++)
		{
			if ((m & 1) != (n & 1))
			{
				count++;
			}
			m = m >> 1;
			n = n >> 1;
		}
		return count;
	}
	int main()
	{
		int m, n;
		scanf("%d%d", &m, &n);
		printf("%d\n",diff_bit(m,n));
		system("pause");
		return 0;
	}