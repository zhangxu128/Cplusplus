//题目描述
//利用字符重复出现的次数，编写一个方法，实现基本的字符串压缩功能。
//比如，字符串“aabcccccaaa”经压缩会变成“a2b1c5a3”。若压缩后的字符串没有变短，则返回原先的字符串。
//给定一个string iniString为待压缩的串(长度小于等于10000)，
//保证串内字符均由大小写英文字母组成，返回一个string，为所求的压缩后或未变化的串。
//测试样例
//"aabcccccaaa"
//返回："a2b1c5a3"
//"welcometonowcoderrrrr"
//返回："welcometonowcoderrrrr"


#include <iostream>
#include <string >

using namespace std;

string zipString(string iniString) {
	// write code here
	string str;
	int i = 0, j = 0;
	while (i < iniString.length()) {
		while (iniString[i] == iniString[j]) i++;
		str += iniString[j];
		str += to_string(i - j);
		j = i;
	}
	if (iniString.length() < str.length()) 
		return iniString;
	else 
		return str;
}

int main(void) {

	string s;
	cin >> s;
	cout << zipString(s) << endl;

	system("pause");
	return 0;
}