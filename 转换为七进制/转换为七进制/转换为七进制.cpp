#include <iostream>
#include <string>

using namespace std;

//给定一个整数，将其转化为7进制，并以字符串形式输出。
//
//示例 1:
//
//输入: 100
//	输出 : "202"
//	示例 2 :
//
//	输入 : -7
//	输出 : "-10"

string convertToBase7(int num) {
	
	string s = "";
	bool flag = false;
	if (num < 0) {
		num = -num;
		flag = true;
	}
	
	while (num != 0) {
		int tmp = num % 7;
		s += to_string(tmp);
		num /= 7;
	}
	reverse(s.begin(), s.end());
	if (flag) {
		s = "-" + s;
	}
	return s;
}

int main(void) {

	cout << "请输入一个数字" << endl;
	int n;
	cin >> n;
	string s = convertToBase7(n);
	cout << "转换为七进制为:" << s << endl;
	system("pause");
	return 0;
}