#include<stdio.h>
#include<stdlib.h>

int main()
{
	//��ӡ�˷��ھ���
	for (int row = 1; row <= 9; row++)
	{
		for (int col = 1; col <=row; col++)
		{
			printf("%d*%d=%d\t", row, col, row*col);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}