#include<iostream>
#include<map>

using namespace std;

//给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
//
//  示例 1:
//
//  输入: "abcabcbb"
//	输出 : 3
//	解释 : 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
//	示例 2 :
//
//	输入 : "bbbbb"
//	输出 : 1
//	解释 : 因为无重复字符的最长子串是 "b"，所以其长度为 1。
//	示例 3 :
//
//	输入 : "pwwkew"
//	输出 : 3
//	解释 : 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//	请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

int max(int a, int b)
{
	return a > b ? a : b;
}

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		map<char, int> m;//map<character,index>
		int maxLen = 0;
		int start = 0;
		for (unsigned int i = 0; i < s.size(); i++) {
			if (m.count(s[i]) > 0) {
				start = max(start, m[s[i]] + 1); //加max的原因：start只能往前走，不能往后退。
			}
			maxLen = max(maxLen, i - start + 1);//本题求最大，故加max。
			m[s[i]] = i; //无论是否重复，都更新字符对应的下标为：当前字符串最新出现该字符的下标。
		}
		return maxLen;
	}
};

int main()
{
	Solution s;
	cout << s.lengthOfLongestSubstring("pwwkew") <<endl;
	system("pause");
	return 0;
}