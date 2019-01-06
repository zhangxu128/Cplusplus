#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int gys_gbs(int a, int b)
{
	int c,m,n;
	m = a;
	n = b;
	while (b != 0)  /* 余数不为0，继续相除，直到余数为0 */
	{
		c = a % b; a = b;  b = c;
	}
	printf("最大公约数:%d\n", a);
	printf("最小公倍数:%d\n", m*n / a);
}
int main()
{
	int a, b;
	scanf("%d%d",&a,&b);
	gys_gbs(a,b);
	system("pause");
	return 0;
}