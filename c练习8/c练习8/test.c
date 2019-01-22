#include<stdio.h>
#include<stdlib.h>
int main()
{
	double sum = 0;
	for (double i = 1; i <= 99; i+=2)
	{
		sum += 1 / i;
	}
	for (double i = 2; i <= 100; i += 2)
	{
		sum += (-1 / i);
	}
	printf("%f\n",sum);
	system("pause");
	return 0; 
}
