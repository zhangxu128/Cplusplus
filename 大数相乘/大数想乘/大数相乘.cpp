//给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
//示例 1:
//输入: num1 = "2", num2 = "3"
//	输出 : "6"
//	示例 2 :
//	输入 : num1 = "123", num2 = "456"
//	输出 : "56088"
//	说明
//	num1 和 num2 的长度小于110。
//	num1 和 num2 只包含数字 0 - 9。
//	num1 和 num2 均不以零开头，除非是数字 0 本身。
//	不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。

#include <iostream>
#include <string>

using namespace std;

string multiply(string num1, string num2) {
	if (num1 == "0" || num2 == "0")
		return "0";
	int size1 = num1.size(), size2 = num2.size();
	string str(size1 + size2, '0');
	for (int i = size1 - 1; i >= 0; i--) {
		int mulflag = 0;
		int addflag = 0;
		for (int j = size2 - 1; j >= 0; j--) {
			int tmp = (num1[i] - '0') * (num2[j] - '0') + mulflag;
			mulflag = tmp / 10;
			tmp = tmp % 10;
			int tmp2 = str[i + j + 1] - '0' + tmp + addflag;
			str[i + j + 1] = tmp2 % 10 + '0';
			addflag = tmp2 / 10;
		}
		str[i] += mulflag + addflag;
	}
	if (str[0] == '0')
		str = str.substr(1, str.size());
	return str;
}


int main(void) {
	cout << "输入两个数字" << endl;
	string s1;
	string s2;
	cin >> s1 >> s2;
	cout << multiply(s1, s2) << endl;
	system("pause");
	return 0;
}