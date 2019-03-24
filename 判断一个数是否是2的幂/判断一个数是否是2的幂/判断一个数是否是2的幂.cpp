#include<iostream>

using namespace std;

//给定一个整数，编写一个函数来判断它是否是 2 的幂次方。
bool isPowerOfTwo(int n) 
{
	if (n <= 0 || n % 2 != 0)
	{
		return false;
	}
	while (n != 2)
	{
		if ((n /= 2) % 2 != 0)
		{

			return false;
		}
	}
	return true;
}

int main()
{
	int num = 0;
	cin >> num;
	cout << isPowerOfTwo(num) << endl;
	system("pause");
	return 0;
}
