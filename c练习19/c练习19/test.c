#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num[] = { 1,2,3,4,5,5,6,4,3,2,1 };
	int temp = 0;
	for (int i = 0; i < 11; i++)
	{
		temp = temp ^ num[i];
	}
	printf("%d\n",temp);
	system("pause");
	return 0;
}