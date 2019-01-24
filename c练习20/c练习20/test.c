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
	/*1.调整数组使奇数全部都位于偶数前面。

		题目：

		输入一个整数数组，实现一个函数，
		来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
		所有偶数位于数组的后半部分。*/
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