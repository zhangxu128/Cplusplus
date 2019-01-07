#include<stdio.h>
#include<stdlib.h>
//求最大值
int getmax(int arr[])
{
	int max = arr[0];
	for (int i = 0; i < 10; i++)
	{
		if (max < arr[i + 1])
		{
			max = arr[i + 1];
		}
	}
	printf("%d\n", max);
	return 0;
}
//排序
int maopao(int arr[])
{
	int temp;
	for(int i=0;i<10;i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (arr[j] < arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
int main()
{
	int arr[10] = {3,5,7,1,64,34,60,23,45,12};
	getmax(arr);
	maopao(arr);
	system("pause");
	return 0;
}