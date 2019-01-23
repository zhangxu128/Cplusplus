#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	for (int i = 100; i < 1000; i++)
	{
		int sum = 0;
		int j = i;
		while (j != 0)
		{
			int temp = j % 10;
			sum += pow(temp, 3);
			j /= 10;
		}
		if (sum == i)
		{
			printf("%d\t", i);
		}
	}
	system("pause");
	return 0;
}