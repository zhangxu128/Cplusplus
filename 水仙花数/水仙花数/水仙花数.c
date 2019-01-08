#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int S_x_h(int n)
{
	int temp=0;
	int sum = 0;
	int m = n;
	while (n != 0) 
	{
		temp = n % 10;
		n = n / 10;
		sum = sum + (int)pow(temp, 3);
	}
	if (sum == m)
	{
		printf("%d\n", m);
	}
	return 0;
}
int main()
{
	for (int i = 100; i < 1000; i++)
	{
		S_x_h(i);
	}
	system("pause");
	return 0;
}