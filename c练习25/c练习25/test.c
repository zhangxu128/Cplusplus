#include<stdio.h>
#include<stdlib.h>
int main()
{
	/*����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ��
		��20Ԫ�����Զ�����ˮ��
		���ʵ�֡�*/
	int price = 1;
	int juice_count = 0;       //  20   10   5  2  1 
	int sum_price = 20;      
	for (int i = 1; i <= sum_price; i++)
	{
		juice_count++;
		if (i % 2 == 0)
		{
			sum_price += 1;
		}
	}
	juice_count--;
	printf("%d\n",juice_count);
	system("pause");
	return 0;
}