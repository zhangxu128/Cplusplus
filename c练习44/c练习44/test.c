#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//Ͱ���� ʱ�临�Ӷ� O(M+N)

int main()
{
	//�Գɼ���������  ����ʮ��   
	//6��ͬѧ�ֱ���  2 5 1 9 5 8 ��
	//���մ�С����ķ�ʽ����Щ������������
	int arr[11] = { 0 };    //��arr��������ʾͰ
	int tmp;
	printf("������Ҫ�����ѧ��������n= ");
	int n;
	scanf("%d", &n);
	printf("������ѧ���ɼ���\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &tmp);  //������ĳɼ����浽����tmp��
		arr[tmp]++;    //��Ͱ�м���
	}
	//���
	printf("ѧ���ɼ����մ�С��������Ϊ��\n");
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		for (int j = 0; j < arr[i]; j++)
		{
			printf("%d\t", i);
		}
	}
	system("pause");
	return 0;
}
