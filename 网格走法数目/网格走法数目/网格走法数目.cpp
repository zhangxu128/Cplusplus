#include<iostream>
using namespace std;

//题目描述
//有一个X*Y的网格，小团要在此网格上从左上角到右下角，只能走格点且只能向右或向下走。
//请设计一个算法，计算小团有多少种走法。给定两个正整数int x, int y，请返回小团的走法数目。
//输入描述 :
//输入包括一行，逗号隔开的两个正整数x和y，取值范围[1, 10]。
//输出描述 :
//输出包括一行，为走法的数目。

//采用递归思路
//f(m,n) 它的必经之路一定是 f(m-1,n) 或者 f(m,n-1)
//所以递归条件就是f(m,n) = f(m-1,n)+f(m,n-1)
//当m 或者 n 等于0 递归结束
int step(int m, int n) {
	if (m == 0 || n == 0)
		return 1;
	return step(m - 1, n) + step(m, n - 1);
}
int main() {
	int x, y;
	cin >> x >> y;
	cout << step(x, y) << endl;
	system("pause");
	return 0;
}