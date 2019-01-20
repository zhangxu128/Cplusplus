#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//打印固定年份之间的闰年
void runYear(int start,int end)
{
	for (start; start <= end; start++)
	{
		if ((start % 4 == 0 && start % 100 != 0) || (start % 400 == 0))
		{
			printf("%d\t", start);
		}
	}
}

int main()
{
	int start, end;
	scanf("%d%d",&start,&end);
	runYear(start,end);
	system("pause");
	return 0;
}