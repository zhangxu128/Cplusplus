#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int gys_gbs(int a, int b)
{
	int c,m,n;
	m = a;
	n = b;
	while (b != 0)  /* ������Ϊ0�����������ֱ������Ϊ0 */
	{
		c = a % b; a = b;  b = c;
	}
	printf("���Լ��:%d\n", a);
	printf("��С������:%d\n", m*n / a);
}
int main()
{
	int a, b;
	scanf("%d%d",&a,&b);
	gys_gbs(a,b);
	system("pause");
	return 0;
}