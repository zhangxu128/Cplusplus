#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//题目描述
//输入一串字符，包含数字[0 - 9]和小写字母[a - z]，要求按数字从小到大、字母从a到z排序，
//并且所有数字排在字母后面
//输入描述 :
//一串字符
//输出描述 :
//按规则排序的一串字符
//示例1
//输入
//a31bz
//输出
//abz13

int main() {
	string str;
	cin >> str;
	sort(str.begin(), str.end());
	int temp = 0;//保存字母开始的下标
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			temp = i;
			break;
		}
	}
	string s;
	for (int i = temp; i < str.size(); i++) {
		s.push_back(str[i]);
	}
	for (int i = 0; i < temp; i++) {
		s.push_back(str[i]);
	}
	cout << s << endl;
	system("pause");
	return 0;
}