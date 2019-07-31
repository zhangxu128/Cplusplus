//题目描述
//给定一个仅由小写字母组成的字符串。现在请找出一个位置，删掉那个字母之后，字符串变成回文。请放心总会有一个合法的解。如果给定的字符串已经是一个回文串，那么输出 - 1。
//输入描述 :
//第一行包含T，测试数据的组数。后面跟有T行，每行包含一个字符串。
//输出描述 :
//如果可以删去一个字母使它变成回文串，则输出任意一个满足条件的删去字母的位置（下标从0开始）。例如：
//bcc
//我们可以删掉位置0的b字符。
//示例1
//输入
//3
//aaab
//baa
//aaa
//输出
//3
//0
//- 1

#include<iostream>
#include <algorithm>
#include<string>
using namespace std;
int main() {
	string str, str1, str2;
	int n;
	cin >> n;
	while (n--)
	{
		cin >> str;
		str1 = str;
		str2 = str;
		reverse(str1.begin(), str1.end());
		int i = 0;
		if (str1 != str2) {

			do {
				str1 = str;
				str2 = str;
				str2.erase(i++, 1);
				str1 = str2;
				reverse(str1.begin(), str1.end());
			} while (str1 != str2);
			cout << i - 1 << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
	return 0;
}

