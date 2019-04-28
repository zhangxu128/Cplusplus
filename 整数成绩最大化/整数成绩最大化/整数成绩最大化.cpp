//题目描述
//给出一个整数n，将n分解为至少两个整数之和，使得这些整数的乘积最大化，输出能够获得的最大的乘积。
//例如：
//2 = 1 + 1，输出1；
//10 = 3 + 3 + 4，输出36。
//输入描述 :
//输入为1个整数
//输出描述 :
//输出为1个整数
//示例1
//输入
//10
//输出
//36

#include <iostream>
using namespace std;

int getMax(int n) {
	int max = 1;
	int i;
	for (i = n; i >= 4; i -= 3) {
		if (n == 4) {
			max = max * 4;
		}
		else {
			max = max * 3;
		}
	}
	if (i == 3) {
		max = max * 3;
	}
	else if (i == 2) {
		max = max * 2;
	}

	return max;
}

int main(void) {
	int n;
	cin >> n;
	if (n == 1) {
		cout << 0 << endl;
	}
	else if (n == 2) {
		cout << 1 << endl;
	}
	else if (n == 3) {
		cout << 2 << endl;
	}
	else {
		int ret = getMax(n);
		cout << ret << endl;
	}
	system("pause");
	return 0;
}