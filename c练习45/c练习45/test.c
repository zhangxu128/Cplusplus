#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//��һ���������� 25 634 192 2 69 20 100 334 ��<1000������������

//1 ����Ͱ���򷽷�
void tong_sort(int arr[], int size)
{
	int array[1000] = { 0 };
	int tmp;
	for (int i = 0; i < size; i++)
	{
		tmp = arr[i];
		array[tmp]++;
	}
	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < array[i]; j++)
		{
			printf("%d\t", i);
		}
	}
}

//2 ����ð������
void bubble_sort(int arr[], int size)
{
    for(int i = 0;i<size-1;i++)
	{
		for (int j = 0; j < size - i; j++)
		{
			int temp;
			if (arr[j] < arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		printf("%d\t", arr[i]);
	}
}


//3 ���ÿ�������   (�һ�׼��)
void quick_sort(int arr[], int size,int left,int right)
{
	int temp;   //��׼��
	int l = left;
	int r = right;
	temp = arr[left];
	if (left > right)
	{
		return;
	}
	while (l != r)
	{
		while (arr[r] >= temp && l < r)
		{
			r--;   //����������һ��С�ڻ�׼������
		}
		while (arr[l] <= temp && l < r)
		{
			l++;   //����������һ�����ڻ�׼������
		}
		//�������������н���
		if (l < r)
		{
			arr[l] = arr[l] ^ arr[r];
			arr[r] = arr[l] ^ arr[r];
			arr[l] = arr[l] ^ arr[r];
		}
	}
	//����׼����λ
	arr[left] = arr[l];
	arr[l] = temp;

	quick_sort(arr, size, left, l - 1);
	quick_sort(arr, size, r + 1, right);
}


int main()
{
	//����������
	int arr[] = { 25, 634, 192, 2, 69, 20, 100, 334 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int left = 0;
	int right = size - 1;
	tong_sort(arr, size);
	printf("\n");
	bubble_sort(arr, size);
	printf("\n");
	quick_sort(arr, size,left,right);
	for (int i = 0; i < size; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}