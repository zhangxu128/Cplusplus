//����һ���Ǹ����� n�������λ���ֶ���ͬ������ x �ĸ��������� 0 �� x < 10n ��
//	ʾ�� :
//����: 2
//	��� : 91
//	���� : ��ӦΪ��ȥ 11, 22, 33, 44, 55, 66, 77, 88, 99 �⣬��[0, 100) �����ڵ��������֡�


#include <iostream>

using namespace std;


int countNumbersWithUniqueDigits(int n) {
	if (0 == n) return 1;
	if (1 == n) return 10;
	int sum = 10;
	int dp = 9;
	for (int i = 2; i <= n; ++i)
	{
		dp = dp * (10 - i + 1);
		sum += dp;
	}
	return sum;
}

int main(void) {

	cout << "������n=";
	int n;
	cin >> n;
	cout << countNumbersWithUniqueDigits(n) << endl;
	system("pause");
	return 0;
}