#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num;
	int count = 0;
	for (num = 1; num < 100; num++)
	{
		int i = num;
		while (i != 0)
		{
			if (i % 10 == 9)
			{
				count++;
			}
			i /= 10;
		}
	}
	printf("%d\n",count);
	system("pause");
	return 0;
}