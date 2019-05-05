//题目描述
//给出直角三角坐标平面上三角形其中两个顶点的坐标，求第三个顶点的坐标，要求保留小数点后两位小数
//输入描述 :
//有多组测试数据，输入的第一行是整数T(1≤T≤200)表示随后测试数据的组数。
//每组测试数据占一行，由4个带两位小数由一个空格隔开的实数构成，表示已知的两个顶点的横纵坐标。
//输出描述 :
//对应每组测试数据，输出对应的第三个顶点（两组解），如果两组解的横坐标不相等，则先输出横坐标较小的顶点，否则输出纵坐标较小的顶点，每组输出占一行，输出保留两位小数
//示例1
//输入
//3
//12.00 3.00 12.00 9.00
//12.00 3.00 24.00 3.00
//1.00 2.00 3.00 4.00
//输出
//6.80 6.00 17.20 6.00
//18.00 - 7.39 18.00 13.39
//0.27 4.73 3.73 1.27

#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


void solve(double x1, double y1, double x2, double y2)
{
	double vx = x2 - x1, vy = y2 - y1, sqrt3 = sqrt(3);
	double ans1x, ans1y, ans2x, ans2y;
	ans1x = (vx + sqrt3 * vy) * 0.5 + x1;
	ans1y = (vy - sqrt3 * vx) * 0.5 + y1;
	ans2x = (vx - sqrt3 * vy) * 0.5 + x1;
	ans2y = (vy + sqrt3 * vx) * 0.5 + y1;
	if (ans1x == ans2x)
	{
		x1 = x2 = ans1x;
		y1 = ans1y < ans2y ? ans1y : ans2y;
		y2 = ans1y > ans2y ? ans1y : ans2y;
	}
	else if (ans1x > ans2x)
	{
		x1 = ans2x;
		y1 = ans2y;
		x2 = ans1x;
		y2 = ans1y;
	}
	else
	{
		x1 = ans1x;
		y1 = ans1y;
		x2 = ans2x;
		y2 = ans2y;
	}
	printf("%.2f %.2f %.2f %.2f\n", x1, y1, x2, y2);
}

int main()
{
	int T;
	double x1, y1, x2, y2;
	//freopen("/home/pilgrimway/Documents/testCase", "r", stdin);
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
		solve(x1, y1, x2, y2);
	}
	system("pause");
	return 0;
}