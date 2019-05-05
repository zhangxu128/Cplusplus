#include <iostream>
#include <cmath>

using namespace std;

//题目描述
//令Pi表示第i个素数。现任给两个正整数M <= N <= 10000，
//请输出PM到PN的所有素数。
//输入描述 :
//输入在一行中给出M和N，其间以空格分隔。
//输出描述 :
//输出从PM到PN的所有素数，每10个数字占1行，
//其间以空格分隔，但行末不得有多余空格。
//输入例子 :
//5 27
//输出例子 :
//	11 13 17 19 23 29 31 37 41 43
//	47 53 59 61 67 71 73 79 83 89
//	97 101 103

//思路：先求出第M个素数，然后开始计数输出

bool isprime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {

	int m, n;
	cin >> m >> n;

	int cnt = 0;
	int i = 2;
	int count = 0;
	while (1) {
		if (isprime(i)) {
			cnt++;
			if (cnt >= m && cnt <= n) {
				count++;
				if (count <= 9) {
					cout << i << " ";
				}
				if (count == 10) {
					cout << i << endl;
					count = 0;
				}
			}
			if (cnt > n) {
				break;
			}

		}
		i++;
	}
	cout << endl;
	system("pause");
	return 0;
}