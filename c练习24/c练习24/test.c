#include<stdio.h>
#include<stdlib.h>
//函数功能 ： 找出数组中两个只出现一次的数字  
//函数参数 ： arr为源数组，len为数组元素个数，result用来存放结果   
//返回值   ： 无 
void FindIsolateTwo(int *arr, int len, int *result)
{
	int i, all = 0, flag = 1;

	for (i = 0; i < len; i++) //所有数异或  
		all ^= arr[i];

	while (!(all&flag))  //寻找过滤位  
		flag <<= 1;

	for (i = 0; i < len; i++) //利用过滤位区分  
	{
		if (flag&arr[i])
			result[0] ^= arr[i];
		else
			result[1] ^= arr[i];
	}
}
int main()
{
	/*一个数组中只有两个数字是出现一次，
		其他所有数字都出现了两次。
		找出这两个数字，编程实现。*/
	int arr[] = {1,2,4,5,3,5,1,2};
	int temp = 0;
	int len = sizeof(arr) / sizeof(arr[0]);
	int result[] = {0};
	FindIsolateTwo(arr, len, result);
	printf("这两个数分别是：%d %d\n", result[0], result[1]);
	system("pause");
	return 0;
}