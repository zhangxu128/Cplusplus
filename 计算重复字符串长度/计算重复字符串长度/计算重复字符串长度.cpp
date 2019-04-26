#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


//题目描述
//请从字符串中找出至少重复一次的子字符串的最大长度
//输入描述 :
//字符串，长度不超过1000
//输出描述 :
//重复子串的长度，不存在输出0
//示例1
//输入
//ababcdabcefsgg
//输出
//3
//abc为重复的最大子串，长度为3

size_t getCommLen(string str1, string str2) {
	size_t i;
	for (i = 0; i < str1.size() && i < str2.size(); i++) {
		if (str1[i] != str2[i])
			break;
	}
	return i;
}
int main()
{
	string str;
	cin >> str;
	vector<string> strs;
	for (size_t i = 0; i < str.size(); i++) {
		strs.push_back(str.substr(i));
	//	cout << str.substr(i) << " ";
	}
	//cout << endl;
	sort(strs.begin(), strs.end());
	//如果有相同字串，必定相邻
	size_t maxLen = 0;
	for (size_t i = 0; i < strs.size() - 1; i++) {
		size_t len = getCommLen(strs[i], strs[i + 1]);
		maxLen = max(maxLen, len);
	}
	cout << maxLen << endl;
	system("pause");
	return 0;
}