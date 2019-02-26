#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student //定义结构体
{
	char name[10];  //定义姓名
	double grade;   //定义成绩
	int age;		//定义年龄
};

int int_compar(const void *p, const void *q)//比较两个数的大小
{
	return *((int *)p) - *((int *)q);
}

int struct_int_com(const void *p, const void *q)//结构体整形比较
{
	return ((struct student*)p)->age - ((struct student*)q)->age;
}

int struct_str_com(const void *p, const void *q)//结构体字符串比较
{
	return (strcmp((*(struct student*)p).name, (*(struct student*) q).name));
}

int struct_double_com(const void *p, const void *q)//结构体浮点型比较
{
	return ((*(struct student*)p).grade > ((struct student*)q)->grade);
}

void swap_num(void *p, void *q, int size)//交换两个数的函数
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		char tmp = *((char *)p + i);
		*((char *)p + i) = *((char *)q + i);
		*((char *)q + i) = tmp;
	}
}

void bubble_sort(void * arr,/*要排序的数组*/
	int num, /*数组元素个数*/
	int size,/*每个元素占的字节数*/
	int(*compar)(const void *, const void *))/*函数指针，用来比较两个元素的大小，大于返回正值，等于返回零，小于返回负值*/
{
	int i = 0;
	int j = 0;
	for (i = 0; i < num - 1; i++)
	{
		for (j = 0; j < num - 1 - i; j++)
		{
			if (compar((char *)arr + j * size, (char *)arr + (j + 1)*size) > 0)
			{
				swap_num((char *)arr + j * size, (char *)arr + (j + 1)*size, size);
			}
		}
	}
}

void print_num(int *arr, int sz)//打印整形数组
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void print_struct(struct student arr[], int sz)//打印结构体数组
{
	int i = 0;
	printf("姓名\t成绩\t年龄\n");
	for (i = 0; i < sz; i++)
	{
		printf("%s\t%.2lf\t%d\n", arr[i].name, arr[i].grade, arr[i].age);
	}
	printf("\n");
}


int main()
{
	int i = 0;

	int arr_int[10] = { 1, 2, 5, 8, 6, 4, 7, 3, 80, 10 };
	char *arr_str[] = { "bcdef", "abcde", "efghi", "defgh", "cdefg" };

	struct student arr_stu[3] = { {"xiaomin",96.5, 18}, {"lisi", 88.2, 19}, {"wangwu", 66.9, 15} };
	//排序整形数字
	printf("给整形数字排序>\n");
	bubble_sort(arr_int, sizeof(arr_int) / sizeof(arr_int[0]), sizeof(arr_int[0]), int_compar);
	print_num(arr_int, sizeof(arr_int) / sizeof(arr_int[0]));
	printf("\n");

	//排序结构体中的整形
	printf("按结构体中的（年龄）整形排序>\n");
	bubble_sort(arr_stu, sizeof(arr_stu) / sizeof(arr_stu[0]), sizeof(arr_stu[0]), struct_int_com);
	print_struct(arr_stu, sizeof(arr_stu) / sizeof(arr_stu[0]));

	//排序结构体中的字符串
	printf("按结构体中的（姓名）字符串排序>\n");
	bubble_sort(arr_stu, sizeof(arr_stu) / sizeof(arr_stu[0]), sizeof(arr_stu[0]), struct_str_com);
	print_struct(arr_stu, sizeof(arr_stu) / sizeof(arr_stu[0]));

	//排序结构体中的浮点型数字
	printf("按结构体中的浮点型（成绩）排序>\n");
	bubble_sort(arr_stu, sizeof(arr_stu) / sizeof(arr_stu[0]), sizeof(arr_stu[0]), struct_double_com);
	print_struct(arr_stu, sizeof(arr_stu) / sizeof(arr_stu[0]));

	system("pause");
	return 0;
}