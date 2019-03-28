#include<iostream>

using namespace std;
//
//对于一个 正整数，如果它和除了它自身以外的所有正因子之和相等，我们称它为“完美数”。
//给定一个 正整数 n， 如果他是完美数，返回 True，否则返回 False
//示例：
//  输入 : 28
//	输出 : True
//	解释 : 28 = 1 + 2 + 4 + 7 + 14

bool checkPerfectNumber(int num) 
{
	int tmp = num;
	int sum = 0;
	if (num == 1)
	{
		return false;
	}
	for (int i = 2; i <= sqrt(num); i++)
	{
		if (tmp%i == 0)
		{
			sum += i;
			sum += (tmp / i);
		}
	}
	if ((sum+1) == num)
	{
		return true;
	}

	return false;
}

int main()
{
	int n;
	cin >> n;
	cout << checkPerfectNumber(n) << endl;
	system("pause");
	return 0;
}