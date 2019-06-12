//题目描述
//写出一个程序，接受一个由字母和数字组成的字符串，和一个字符，然后输出输入字符串中含有该字符的个数。不区分大小写。
//输入描述 :
//输入一个有字母和数字以及空格组成的字符串，和一个字符。
//输出描述 :
//输出输入字符串中含有该字符的个数。
//示例1
//输入
//ABCDEF A
//输出
//1

#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

int main(void) {

	string s;  //输入字符串
	char c;    // 输入字符

	cin >> s >> c;

	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (((s[i]>='a'&& s[i] <= 'z')|| (s[i] >= 'A'&& s[i] <= 'Z')) && ((s[i] == c) || (s[i]==c+32) || (s[i] == c-32))) {
			cnt++;
		}
	}
	cout << cnt << endl;
	system("pause");
	return 0;
}