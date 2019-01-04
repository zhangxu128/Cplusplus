#include<stdio.h>
#include<stdlib.h>
int main()
{
	double sum = 0;
	int flag = 1;
	for (int i = 1; i <= 100; i++) {
		sum = sum + 1.0 / i*flag;
		flag = flag * -1;
	}
	printf("%f\n", sum);
	system("pause");
	return 0;
}