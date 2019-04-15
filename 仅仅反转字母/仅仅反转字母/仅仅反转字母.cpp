#include<iostream>
#include <string>

using namespace std;
//给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。
//示例 1：
//输入："ab-cd"
//输出："dc-ba"
//示例 2：
//输入："a-bC-dEf-ghIj"
//输出："j-Ih-gfE-dCba"

class Solution {
public:
	string reverseOnlyLetters(string S) {
		int left = 0;
		int right = S.size() - 1;
		while (left < right) {
			if (S[left] >= 'A'&&S[left] <= 'Z' || S[left] >= 'a'&&S[left] <= 'z') {
				if (S[right] >= 'A'&&S[right] <= 'Z' || S[right] >= 'a'&&S[right] <= 'z') {
					char tmp = S[left];
					S[left] = S[right];
					S[right] = tmp;
					left++;
					right--;
				}
				else {
					right--;
					continue;
				}
			}
			else {
				left++;
			}
		}
		return S;
	}
};
int main() {

	string str = "afa-Fff--das";
	Solution s;
	string s1 = s.reverseOnlyLetters(str);
	cout << s1 << endl;
	system("pause");
	return 0;
}