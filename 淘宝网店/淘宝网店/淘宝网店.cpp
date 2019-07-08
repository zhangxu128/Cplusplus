//��Ŀ����
//NowCoder���Ա��Ͽ���һ�����ꡣ���������·�Ϊ������ʱ�򣬵���ÿ����׬1Ԫ������ÿ����׬2Ԫ��
//���ڸ���һ��ʱ�����䣬������������������ж��١�
//�������� :
//��������������ݡ�
//ÿ�����ݰ�����������from��to(2000 - 01 - 01 �� from �� to �� 2999 - 12 - 31)��
//������������������ʾ���ÿո������year month day��
//������� :
//��Ӧÿһ�����ݣ�����ڸ��������ڷ�Χ��������ʼ�ͽ������ڣ�����׬����Ǯ��
//ʾ��1
//����
//2000 1 1 2000 1 31
//2000 2 1 2000 2 29
//���
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