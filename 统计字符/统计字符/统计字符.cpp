#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//题目描述
//给定一个英文字符串, 请写一段代码找出这个字符串中首先出现三次的那个英文字符(需要区分大小写)。

bool getcount(char c,int k, string s) {
	int count = 1;
	for (int i = k+1; i < s.size(); i++) {
		if (c == s[i]) {
			count++;
			if (count >= 3) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	
	string  s;
	getline(cin, s);
	int i;
	for (i = 0; i < s.size(); i++) {
		if (getcount(s[i],i,s)) {
			break;
		}
	}
	cout << s[i] << endl;
	system("pause");
	return 0;
}