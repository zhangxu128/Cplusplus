#include <iostream>
#include <string>

//给定一个字符串和一个整数 k，你需要对从字符串开头算起的每个 2k 个字符的前k个字符进行反转。
//如果剩余少于 k 个字符，则将剩余的所有全部反转。如果有小于 2k 但大于或等于 k 个字符，则反转前 k 个字符，
//并将剩余的字符保持原样。
//示例 :
//输入: s = "abcdefg", k = 2
//	输出 : "bacdfeg"
//	要求 :
//	该字符串只包含小写的英文字母。
//	给定字符串的长度和 k 在[1, 10000]范围内。

using namespace std;

//利用反转函数在原地反转
string reverseStr(string s, int k) {
	int p = 0;
	while (s.size() - p >= 2 * k) {
		reverse(s.begin() + p, s.begin() + p + k);
		p += (2 * k);
	}
	if (s.size() - p >= k) reverse(s.begin() + p, s.begin() + p + k);
	else reverse(s.begin() + p, s.end());
	return s;
}

int main(void){

	cout << "请输入一个字符串s:" << endl;
	string s;
	cin >> s;
	cout << "请输入反转步长" << endl;
	int k;
	cin >> k;
	cout << "按规律反转字符串后为：" << reverseStr(s, k) << endl;
	system("pause");
	return 0;
}