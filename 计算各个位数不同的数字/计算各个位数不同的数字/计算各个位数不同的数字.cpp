//给定一个非负整数 n，计算各位数字都不同的数字 x 的个数，其中 0 ≤ x < 10n 。
//	示例 :
//输入: 2
//	输出 : 91
//	解释 : 答案应为除去 11, 22, 33, 44, 55, 66, 77, 88, 99 外，在[0, 100) 区间内的所有数字。


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

	cout << "请输入n=";
	int n;
	cin >> n;
	cout << countNumbersWithUniqueDigits(n) << endl;
	system("pause");
	return 0;
}