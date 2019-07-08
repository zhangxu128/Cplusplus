//题目描述
//NowCoder在淘宝上开了一家网店。他发现在月份为素数的时候，当月每天能赚1元；否则每天能赚2元。
//现在给你一段时间区间，请你帮他计算总收益有多少。
//输入描述 :
//输入包含多组数据。
//每组数据包含两个日期from和to(2000 - 01 - 01 ≤ from ≤ to ≤ 2999 - 12 - 31)。
//日期用三个正整数表示，用空格隔开：year month day。
//输出描述 :
//对应每一组数据，输出在给定的日期范围（包含开始和结束日期）内能赚多少钱。
//示例1
//输入
//2000 1 1 2000 1 31
//2000 2 1 2000 2 29
//输出
//62
//29

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 13;
int mod[N] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int moPer[N] = { 0, 2, 1, 1, 2, 1, 2, 1, 2, 2, 2, 1, 2 };
int money[N];
int moYear;

void init()
{
	for (int i = 1; i < N; i++)
		money[i] = (money[i - 1] + mod[i] * moPer[i]);
	moYear = money[12];
}

int isRun(int n)
{
	if (n % 4 == 0 && n % 100 != 0)
		return 1;
	else if (n % 400 == 0)
		return 1;
	return 0;
}

int main()
{
	init();
	int y1, y2, m1, m2, d1, d2, res;
	while (cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2)
	{
		res = (y2 - y1)*moYear;
		for (int i = y1; i < y2; i++)
			res += isRun(i);
		res -= (money[m1 - 1] + (moPer[m1] * (d1 - 1)));
		if (m1 > 2) res -= isRun(y1);
		res += (money[m2 - 1] + (moPer[m2] * d2));
		if (m2 > 2) res += isRun(y2);
		printf("%d\n", res);
	}
	return 0;
}