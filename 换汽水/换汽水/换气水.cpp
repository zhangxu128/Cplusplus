//商店规定：三个空瓶可以换一瓶汽水
//假如有n个空瓶，最多可以换几瓶汽水

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
		// 空瓶数
		int emp = n;
		int drink;
		while (emp >= 3) {
			drink = emp / 3;
			sum += drink;
			emp = emp - drink * 3 + drink;
		}
		if (emp == 2) {
			sum += 1;
		}
		cout << sum << endl;
	}

	system("pause");
	return 0;
}