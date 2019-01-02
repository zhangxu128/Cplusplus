//猜数字小游戏（0-100）
//游戏思路
/*
   1、游戏界面函数（功能1开始游戏，功能2退出游戏）
   2、开始游戏函数（大于或者小于被猜数字输出提示，用户继续输入，直至猜中为止）
   3、退出游戏
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//菜单
int menu()
{
	printf("*********************\n");
	printf("1、开始游戏\n");
	printf("2、退出游戏\n");
	printf("*********************\n");
	return 0;
}
//开始游戏
int start_game(int target)
{
	while (1)
	{
		printf("请输入您的猜的数字：");
		int to_guess = 0;
		scanf("%d", &to_guess);
		if (to_guess < target)
		{
			printf("您猜的数字小了\n");
		}
		else if (to_guess > target)
		{
			printf("您猜的数字大了!\n");
		}
		else
		{
			printf("猜中了！\n");
			break;
		}
	}
	return 0;
}
int main()
{
    srand((unsigned int)time(0));
	menu();
	printf("请输入你的选择（1、开始游戏 2、退出游戏）：");
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
			printf("您的输入有误，请重新输入：");
		}
		scanf("%d", &choice);
	}
	system("pause");
	return 0;
}