//题目描述
//米兔从兔米那里了解到有一个无限长的数字序列 1, 2，3，3，4，4，4, 5，5，5，5，5 ..., 
//(已知此数列有一定规律，现将这些数字按不同数值堆叠，相同值的数字在同一层)。
//米兔想知道这个数字序列的第n个数所在的那一层之前的所有层里共有多少个数。
//输入描述 :
//n(n <= 1e18)
//输出描述 :
//	第n个数所在的那一层之前的所有层里共有多少个数
//	示例1
//	输入
//	6
//	输出
//	4

#include <iostream>
using namespace std;

int main() {
	long long input;
	cin >> input;
	long long formal = 0;
	long long now = 1;
	long long count = 0;

	while (1) {
		if (count + now >= input) {
			cout << count << endl;
			break;
		}
		count += now;
		long long tmp = now;
		now = formal + now;
		formal = tmp;
	}
	return 0;
}