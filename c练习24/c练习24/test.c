#include<stdio.h>
#include<stdlib.h>
//�������� �� �ҳ�����������ֻ����һ�ε�����  
//�������� �� arrΪԴ���飬lenΪ����Ԫ�ظ�����result������Ž��   
//����ֵ   �� �� 
void FindIsolateTwo(int *arr, int len, int *result)
{
	int i, all = 0, flag = 1;

	for (i = 0; i < len; i++) //���������  
		all ^= arr[i];

	while (!(all&flag))  //Ѱ�ҹ���λ  
		flag <<= 1;

	for (i = 0; i < len; i++) //���ù���λ����  
	{
		if (flag&arr[i])
			result[0] ^= arr[i];
		else
			result[1] ^= arr[i];
	}
}
int main()
{
	/*һ��������ֻ�����������ǳ���һ�Σ�
		�����������ֶ����������Ρ�
		�ҳ����������֣����ʵ�֡�*/
	int arr[] = {1,2,4,5,3,5,1,2};
	int temp = 0;
	int len = sizeof(arr) / sizeof(arr[0]);
	int result[] = {0};
	FindIsolateTwo(arr, len, result);
	printf("���������ֱ��ǣ�%d %d\n", result[0], result[1]);
	system("pause");
	return 0;
}