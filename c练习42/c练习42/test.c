#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>


//����һ���������飬����Ҫ��ԭ��ɾ���ظ����ֵ�Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Σ������Ƴ���������³��ȡ�
//
//��Ҫʹ�ö��������ռ䣬�������ԭ���޸��������鲢��ʹ�� O(1) ����ռ����������ɡ�
//
//ʾ�� 1:
//
//�������� nums = [1, 1, 2],
//
//����Ӧ�÷����µĳ��� 2, ����ԭ���� nums ��ǰ����Ԫ�ر��޸�Ϊ 1, 2��
//
//�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
//ʾ�� 2:
//
//���� nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4],
//
//����Ӧ�÷����µĳ��� 5, ����ԭ���� nums ��ǰ���Ԫ�ر��޸�Ϊ 0, 1, 2, 3, 4��


int removeDuplicates(int* nums, int numsSize) {
	int i = 0;
	int j = 0;
	if (numsSize == 0)
	{

		return 0;
	}
	while (i < numsSize - 1)
	{
		if (nums[i] != nums[i + 1])
		{
			nums[j + 1] = nums[i + 1];
			j++;
		}
		i++;
	}
	printf("�޸ĺ�����飺");
	for (int m = 0; m < j + 1; m++)
	{
		printf("%d ", nums[m]);
	}
	printf("\n");
	return j + 1;
}

int main()
{
	int arr[] = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
	int len = sizeof(arr) / sizeof(int);
	int a = removeDuplicates(arr, len);
	printf("%d\n", a);
	system("pause");
	return 0;
}
