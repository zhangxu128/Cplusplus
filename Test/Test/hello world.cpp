#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
double pow(double x,int n)
{
	double sum = 1;
	if (n > 0)
	{

		for (int i = 0; i < n; i++)
		{
			sum = sum * x;
		}
	}
	else if (n == 0)
	{
		return 1;
	}
	else
	{
		for (int i = 0; i > n; i--)
		{
			sum = sum * (x);
		}
		sum = 1 / sum;
	}
	return sum;
}
int main()
{
	double x = 0;
	int n = 0;
	scanf("%lf%d",&x,&n);
	double sum = pow(x,n);
	printf("%.5lf\n",sum);
	system("pause");
	return 0;
}