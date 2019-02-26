#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student //����ṹ��
{
	char name[10];  //��������
	double grade;   //����ɼ�
	int age;		//��������
};

int int_compar(const void *p, const void *q)//�Ƚ��������Ĵ�С
{
	return *((int *)p) - *((int *)q);
}

int struct_int_com(const void *p, const void *q)//�ṹ�����αȽ�
{
	return ((struct student*)p)->age - ((struct student*)q)->age;
}

int struct_str_com(const void *p, const void *q)//�ṹ���ַ����Ƚ�
{
	return (strcmp((*(struct student*)p).name, (*(struct student*) q).name));
}

int struct_double_com(const void *p, const void *q)//�ṹ�帡���ͱȽ�
{
	return ((*(struct student*)p).grade > ((struct student*)q)->grade);
}

void swap_num(void *p, void *q, int size)//�����������ĺ���
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		char tmp = *((char *)p + i);
		*((char *)p + i) = *((char *)q + i);
		*((char *)q + i) = tmp;
	}
}

void bubble_sort(void * arr,/*Ҫ���������*/
	int num, /*����Ԫ�ظ���*/
	int size,/*ÿ��Ԫ��ռ���ֽ���*/
	int(*compar)(const void *, const void *))/*����ָ�룬�����Ƚ�����Ԫ�صĴ�С�����ڷ�����ֵ�����ڷ����㣬С�ڷ��ظ�ֵ*/
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

void print_num(int *arr, int sz)//��ӡ��������
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void print_struct(struct student arr[], int sz)//��ӡ�ṹ������
{
	int i = 0;
	printf("����\t�ɼ�\t����\n");
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
	//������������
	printf("��������������>\n");
	bubble_sort(arr_int, sizeof(arr_int) / sizeof(arr_int[0]), sizeof(arr_int[0]), int_compar);
	print_num(arr_int, sizeof(arr_int) / sizeof(arr_int[0]));
	printf("\n");

	//����ṹ���е�����
	printf("���ṹ���еģ����䣩��������>\n");
	bubble_sort(arr_stu, sizeof(arr_stu) / sizeof(arr_stu[0]), sizeof(arr_stu[0]), struct_int_com);
	print_struct(arr_stu, sizeof(arr_stu) / sizeof(arr_stu[0]));

	//����ṹ���е��ַ���
	printf("���ṹ���еģ��������ַ�������>\n");
	bubble_sort(arr_stu, sizeof(arr_stu) / sizeof(arr_stu[0]), sizeof(arr_stu[0]), struct_str_com);
	print_struct(arr_stu, sizeof(arr_stu) / sizeof(arr_stu[0]));

	//����ṹ���еĸ���������
	printf("���ṹ���еĸ����ͣ��ɼ�������>\n");
	bubble_sort(arr_stu, sizeof(arr_stu) / sizeof(arr_stu[0]), sizeof(arr_stu[0]), struct_double_com);
	print_struct(arr_stu, sizeof(arr_stu) / sizeof(arr_stu[0]));

	system("pause");
	return 0;
}