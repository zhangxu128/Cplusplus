//������С��Ϸ��0-100��
//��Ϸ˼·
/*
   1����Ϸ���溯��������1��ʼ��Ϸ������2�˳���Ϸ��
   2����ʼ��Ϸ���������ڻ���С�ڱ������������ʾ���û��������룬ֱ������Ϊֹ��
   3���˳���Ϸ
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//�˵�
int menu()
{
	printf("*********************\n");
	printf("1����ʼ��Ϸ\n");
	printf("2���˳���Ϸ\n");
	printf("*********************\n");
	return 0;
}
//��ʼ��Ϸ
int start_game(int target)
{
	while (1)
	{
		printf("���������Ĳµ����֣�");
		int to_guess = 0;
		scanf("%d", &to_guess);
		if (to_guess < target)
		{
			printf("���µ�����С��\n");
		}
		else if (to_guess > target)
		{
			printf("���µ����ִ���!\n");
		}
		else
		{
			printf("�����ˣ�\n");
			break;
		}
	}
	return 0;
}
int main()
{
    srand((unsigned int)time(0));
	menu();
	printf("���������ѡ��1����ʼ��Ϸ 2���˳���Ϸ����");
	int choice = 0;
	scanf("%d",&choice);
	int target = rand() % 100 + 1;
	while (1)
	{
		if (choice == 1)
		{
			start_game(target);
			break;
		}
		else if (choice == 2)
		{
			printf("Game Over!\n");
			break;
		}
		else
		{
			printf("���������������������룺");
		}
		scanf("%d", &choice);
	}
	system("pause");
	return 0;
}