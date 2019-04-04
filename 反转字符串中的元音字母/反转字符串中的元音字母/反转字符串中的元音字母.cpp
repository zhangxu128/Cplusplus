#include<iostream>
#include<string>
using namespace std;

//  编写一个函数，以字符串作为输入，反转该字符串中的元音字母。
//  示例 1:
//  输入: "hello"
//	输出 : "holle"
//	示例 2 :
//	输入 : "leetcode"
//	输出 : "leotcede"
 
class Solution {
public:
	bool yuanyin(char c) {
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
			return true;
		}
		return false;
	}
	string reverseVowels(string s) {
		int left = 0;
		int right = s.size() - 1;
		while (left < right) {
			if (this->yuanyin(s[left]) == true) {
				if (this->yuanyin(s[right]) == true) {
					char tem = s[left];
					s[left] = s[right];
					s[right] = tem;
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
		return s;
	}
};
int main()
{
	string s = "hello";
	Solution str;
	cout << str.reverseVowels(s) << endl;
	system("pause");
	return 0;
}