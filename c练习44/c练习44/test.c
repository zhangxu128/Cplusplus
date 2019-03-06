#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//桶排序 时间复杂度 O(M+N)

int main()
{
	//对成绩进行排序  满分十分   
	//6个同学分别考了  2 5 1 9 5 8 分
	//按照从小到大的方式对这些分数进行排序
	int arr[11] = { 0 };    //用arr数组来表示桶
	int tmp;
	printf("请输入要排序的学生人数：n= ");
	int n;
	scanf("%d", &n);
	printf("请输入学生成绩：\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &tmp);  //将输入的成绩保存到变量tmp中
		arr[tmp]++;    //给桶中计数
	}
	//输出
	printf("学生成绩按照从小到大排序为：\n");
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
