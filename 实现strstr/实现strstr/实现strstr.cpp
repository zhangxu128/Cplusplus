#include<iostream>
#include<string>
using namespace std;

//实现 strStr() 函数。
//给定一个 haystack 字符串和一个 needle 字符串，
//在 haystack 字符串中找出 needle 字符串出现的第一个位置(从0开始)
//如果不存在，则返回 - 1。
//示例 1:
//  输入: haystack = "hello", needle = "ll"
//	输出 : 2
//	示例 2 :
//	输入 : haystack = "aaaaa", needle = "bba"
//	输出 : -1

class Solution {
public:
	int strStr(string haystack, string needle) {
		//参数的合法性检验
		if (needle.size() == 0) {
			return 0;
		}
		if (haystack.size() < needle.size()) {
			return -1;
		}
		int j = 0;// 代表needle字符串
		int i = 0;//代表haystack自字符串
		//遍历该字符串，查找有没有相同的一个元素
		for (i = 0; i < haystack.size(); i++) {
			//遍历该字符串，查找有没有相同的一个元素
			if (j == needle.size()) {
				return i - needle.size();
			}
			if (haystack[i] == needle[j]) {
				j++;
			}
			else {
				i -= j;
				j = 0;
			}
		}
		if (j == needle.size()) {
			return i - needle.size();
		}
		return -1;
	}
};

int main(){
	string s1 = "hello";
	string s2 = "ll";
	Solution s;
	cout << s.strStr(s1, s2) << endl;
	system("pause");
	return 0;
}