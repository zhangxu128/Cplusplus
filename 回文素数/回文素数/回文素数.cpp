#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//题目描述
//如果一个整数只能被1和自己整除, 就称这个数是素数。
//如果一个数正着反着都是一样, 就称为这个数是回文数。例如:6, 66, 606, 6666
//如果一个数字既是素数也是回文数, 就称这个数是回文素数
//牛牛现在给定一个区间[L, R], 希望你能求出在这个区间内有多少个回文素数。
//输入描述 :
//输入包括一行, 一行中有两个整数(1 ≤ L ≤ R ≤ 1000)


//判断这个数是不是素数
bool isprime(int n) {
	if (n == 1)return false;
	int i;
	for (i = 2; i <= sqrt(n); i++) {
		if (n%i == 0) {
			return false;
		}
	}

	//判断这个数是不是回文数
	int sum = 0;
	int k = n;
	while (k != 0) {
		int tmp = k % 10;
		sum = sum * 10 + tmp;
		k /= 10;
	}
	if (n == sum) {
		return true;
	}
	return false;
}

int main() {
	int L, R,count = 0;
	cin >> L >> R;
	for (int i = L; i <= R; i++) {
		if (isprime(i)) {
			count++;
		}
	}
	cout << count << endl;
	system("pause");
	return 0;
}