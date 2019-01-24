#include<stdio.h>
#include<stdlib.h>

void func(int a[], int size)
{
	int start = 0;
	int end = size - 1;
	while(start<end)
	{
		for (int i = start; i < size; i++)
		{
			if (a[i] % 2 == 0)
			{
				start = i;
				break;
			}
		}
		for (int i = end; i >= 0; i--)
		{
			if (a[i] % 2 != 0)
			{
				end = i;
				break;
			}
		}
		if (start < end)
		{
			int temp = a[start];
			a[start] = a[end];
			a[end] = temp;
		}
	}

}

int main()
{
	/*1.��������ʹ����ȫ����λ��ż��ǰ�档

		��Ŀ��

		����һ���������飬ʵ��һ��������
		�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
		����ż��λ������ĺ�벿�֡�*/
	int a[] = {1,2,3,4,5,6,7,8,9};
	int size = sizeof(a) / sizeof(a[0]);
	func(a,size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}