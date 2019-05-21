//给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
//注意：
//num1 和num2 的长度都小于 5100.
//num1 和num2 都只包含数字 0 - 9.
//num1 和num2 都不包含任何前导零。
//你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。


#include <iostream>
#include <string>

using namespace std;


//模拟竖式计算方式即可，在这里需要保留进位
string addStrings(string num1, string num2) {
	int len1 = num1.size();
	int len2 = num2.size();
	string s = "";
	int carry = 0;
	while (len1 > 0 || len2 > 0 || carry != 0) {
		if (len1 > 0) {
			carry += num1[--len1] - '0';
		}
		if (len2 > 0) {
			carry += num2[--len2] - '0';
		}
		s += to_string(carry % 10);
		carry /= 10;
	}
	reverse(s.begin(), s.end());
	return s;
}

int main(void) {

	string s1;
	string s2;	
	cin >> s1 >> s2;
	cout << addStrings(s1, s2) << endl;
	system("pause");
	return 0;
}