#include<iostream>
using namespace std;

//给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。
//说明：不要使用任何内置的库函数，如  sqrt。
//示例 1：
//输入：16
//输出：True
//示例 2：
//输入：14
//输出：False

bool isPerfectSquare(int num) {
	/*if (num < 0) {
		return false;
	}
	if (num == 1 || num == 0) {
		return true;
	}
	for (int i = 2; i <= num / 2; i++) {
		
		if ((i * i) == num) {
			return true;
		}
	}
	return false;*/   //超时 复杂
	//另有一种方法完全平方数必定是前n个奇数的和（但此方法可能会越界，超过整数的最大范围）
	//二分查找
	if (num <= 0) return false;
	int left = 0, right = num;    
	while (left < right) {          
		int mid = (left + right + 1ll) / 2;      
		if (mid <= num / mid)
			left = mid;
		else
			right = mid - 1;
	}
	if (left * left == num)
		return true;
	else
		return false;

}

int main()
{
	int num;
	cin >> num;
	//cout << 1ll << endl;
	cout << isPerfectSquare(num) << endl;
	system("pause");
	return 0;
}