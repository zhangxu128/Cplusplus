//给定三条边，请你判断一下能不能组成一个三角形。
//输入描述 :
//输入包含多组数据，每组数据包含三个正整数a、b、c（1≤a, b, c≤10 ^ 100）。
//输出描述 :
//对应每一组数据，如果它们能组成一个三角形，则输出“Yes”；否则，输出“No”。
//示例1
//输入
//1 2 3
//2 2 2
//输出
//No
//Yes


//数字范围大，故用字符串表示。
//用字符串表示整数，定义加法和比较大小的函数
#include <iostream>
#include <string>
using namespace std;

string add(string s1, string s2) {
	int len1 = s1.size();
	int len2 = s2.size();
	string res = "";
	int i, j, k, t = 0;
	for (i = len1 - 1, j = len2 - 1; i >= 0 && j >= 0; i--, j--) {
		k = (s1[i] - '0') + (s2[j] - '0') + t;
		res = (char)(k % 10 + '0') + res;
		t = k / 10;
	}
	while (i >= 0) {
		k = (s1[i] - '0') + t;
		res = (char)(k % 10 + '0') + res;
		t = k / 10;
		i--;
	}
	while (j >= 0) {
		k = (s2[j] - '0') + t;
		res = (char)(k % 10 + '0') + res;
		t = k / 10;
		j--;
	}
	if (t > 0) {
		res = (char)(t + '0') + res;
	}

	return res;
}

bool great(string s1, string s2) {
	int len1 = s1.size();
	int len2 = s2.size();
	if (len1 > len2)
		return true;
	else if (len1 < len2)
		return false;
	else {
		return s1 > s2;
	}

}

int main() {
	string a, b, c;
	while (cin >> a >> b >> c) {
		if (great(add(a, b), c) && great(add(a, c), b) && great(add(b, c), a))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}