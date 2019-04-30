//题目描述
//对于任意两个正整数x和k, 我们定义repeat(x, k)为将x重复写k次形成的数, 例如repeat(1234, 3) = 123412341234, repeat(20, 2) = 2020.
//牛牛现在给出4个整数x1, k1, x2, k2, 其中v1 = (x1, k1), v2 = (x2, k2), 请你来比较v1和v2的大小。
//输入描述 :
//输入包括一行, 一行中有4个正整数x1, k1, x2, k2(1 ≤ x1, x2 ≤ 10 ^ 9, 1 ≤ k1, k2 ≤ 50), 以空格分割
//输出描述 :
//如果v1小于v2输出"Less", v1等于v2输出"Equal", v1大于v2输出"Greater".
//示例1
//输入
//1010 3 101010 2
//输出
//Equal

#include<iostream>
#include<string>

using namespace std;

int main() {
	string x1, x2;
	int k1, k2;
	cin >> x1 >> k1 >> x2 >> k2;
	//  handle x1
	string rep_x1 = x1;
	for (int i = 1; i < k1; i++)
		rep_x1 += x1;
	// hanlde x2
	string rep_x2 = x2;
	for (int i = 1; i < k2; i++)
		rep_x2 += x2;
	if (rep_x1.size() == rep_x2.size()) {
		if (rep_x1 == rep_x2) cout << "Equal" << endl;
		else if (rep_x1 < rep_x2) cout << "Less" << endl;
		else cout << "Greater" << endl;
	}
	else if (rep_x1.size() < rep_x2.size()) cout << "Less" << endl;
	else cout << "Greater" << endl;
	return 0;
}