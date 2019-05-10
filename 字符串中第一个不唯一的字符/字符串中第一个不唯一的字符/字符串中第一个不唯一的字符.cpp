//给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 - 1。
//
//案例 :
//
//s = "leetcode"
//返回 0.
//
//s = "loveleetcode",
//返回 2.

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//adaccdcda  aaacccddd
int firstUniqChar(string s) {
	//以空间换时间
	if (s.size() == 1) {
		return 0;
	}
	int len = s.size();
	int tong[26] = { 0 };
	for (int i = 0; i < len; i++) {
		tong[s[i] - 'a']++;
	}
	for (int i = 0; i < len; i++) {
		if (tong[s[i]-'a'] == 1) {
			return i;
		}
	}
	return -1;
}

int main(void) {

	cout << "输入一个字符串" << endl;
	string s;
	cin >> s;
	cout << "字符串中第一个不唯一 的字符的位置是" << firstUniqChar(s) << endl;
	
	system("pause");
	return 0;
}