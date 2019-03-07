#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//有一组数据例如 25 634 192 2 69 20 100 334 （<1000）并进行排序

//1 采用桶排序方法
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

//2 采用冒泡排序
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


//3 采用快速排序   (找基准数)
void quick_sort(int arr[], int size,int left,int right)
{
	int temp;   //基准数
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
			r--;   //从右往左找一个小于基准数的数
		}
		while (arr[l] <= temp && l < r)
		{
			l++;   //从左往右找一个大于基准数的数
		}
		//将这两个数进行交换
		if (l < r)
		{
			arr[l] = arr[l] ^ arr[r];
			arr[r] = arr[l] ^ arr[r];
			arr[l] = arr[l] ^ arr[r];
		}
	}
	//将基准数归位
	arr[left] = arr[l];
	arr[l] = temp;

	quick_sort(arr, size, left, l - 1);
	quick_sort(arr, size, r + 1, right);
}


int main()
{
	//待排序序列
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