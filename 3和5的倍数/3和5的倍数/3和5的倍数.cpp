//题目描述
//如果我们列出10以内所有3或5的倍数，我们将得到3、5、6和9，这些数的和是23。求n以内所有3或5的倍数的和。
//输入描述 :
//输入n，n不超过2000
//输出描述 :
//输出n以内3或5倍数的和


#include <iostream>

using namespace std;

int main(void) {

	int n;
	while (cin >> n) {
		if (n < 3) {
			cout << 0 << endl;
			continue;
		}
		int sum = 0;
		for (int i = 3; i < n; i++) {
			if (i % 3 == 0 || i % 5 == 0) {
				sum += i;
			}
		}
		cout << sum << endl;
	}

	system("pause");
	return 0;
}