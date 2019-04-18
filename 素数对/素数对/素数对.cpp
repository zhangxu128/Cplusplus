#include<iostream>

using namespace std;

//题目描述
//给定一个正整数，编写程序计算有多少对质数的和等于输入的这个正整数，并输出结果。输入值小于1000。
//如，输入为10, 程序应该输出结果为2。（共有两对质数的和为10, 分别为(5, 5), (3, 7)）


//思路：求出输入从2到n之间的质数
//让这个数减去某个质数，判断另一个数是不是质数

bool isprime(int num,int n) {
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	int count = 0;
	for (int i = 2; i <= n/2; i++) {
		if (isprime(i, n) && isprime(n-i,n)) {
			count++;
		}
	}
	cout << count << endl;
	system("pause");
	return 0;
}