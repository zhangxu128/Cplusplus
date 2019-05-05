//��Ŀ����
//����ֱ����������ƽ��������������������������꣬���������������꣬Ҫ����С�������λС��
//�������� :
//�ж���������ݣ�����ĵ�һ��������T(1��T��200)��ʾ���������ݵ�������
//ÿ���������ռһ�У���4������λС����һ���ո������ʵ�����ɣ���ʾ��֪����������ĺ������ꡣ
//������� :
//��Ӧÿ��������ݣ������Ӧ�ĵ��������㣨����⣩����������ĺ����겻��ȣ���������������С�Ķ��㣬��������������С�Ķ��㣬ÿ�����ռһ�У����������λС��
//ʾ��1
//����
//3
//12.00 3.00 12.00 9.00
//12.00 3.00 24.00 3.00
//1.00 2.00 3.00 4.00
//���
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