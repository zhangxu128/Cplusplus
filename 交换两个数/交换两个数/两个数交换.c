#include<stdio.h>
#include<stdlib.h>
//��ʽһ�������м����
int change1(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
	printf("��ʽһ����֮��a=%d b=%d\n",a,b);
	return 0;
}
//��ʽ������Ҫ�м�����������
int change2(int a, int b)
{
	a = a + b;
	b = a - b;
	a = a - b;
	printf("��ʽ������֮��a=%d b=%d\n", a, b);
	return 0;
}
//��ʽ���������м�����������
int change3(int a, int b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("��ʽ������֮��a=%d b=%d\n", a, b);
	return 0;
}
int main()
{   
	int a = 5;
	int b = 4;
	printf("����֮ǰ��a=%d b=%d\n", a, b);
	change1(5, 4);
	change2(5, 4);
	change3(5, 4);
	system("pause");
	return 0;
}