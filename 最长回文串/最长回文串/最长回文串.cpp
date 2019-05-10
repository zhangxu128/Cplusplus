#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
//在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。
//注意 :
//假设字符串的长度不会超过 1010。
//示例 1 :
//	输入 :
//	"abccccdd"
//	输出 :
//	7
//	解释 :
//	我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。

using namespace std;

//利用栈的特性匹配字符
int longestPalindrome(string s) {
	if (s.size() == 1) {
		return 1;
	}
	sort(s.begin(), s.end());
	int cnt = 0;
	stack<char> stk;
	stk.push(s[0]);
	for (int i = 1; i < s.size(); i++) {
		if (!stk.empty()) {
			char temp = stk.top();
			if (s[i] != temp) {
				stk.push(s[i]);
			}
			else {
				stk.pop();
				cnt += 2;
			}
		}
		else {
			stk.push(s[i]);
		}
		
	}
	if (stk.size()>0) {
		return cnt + 1;
	}
	return cnt;
}

int main(void) {

	cout << "输入一个字符串" << endl;
	string s;
	cin >> s;
	cout << "可以构成最长的回文串的个数是" << longestPalindrome(s) << endl;
	system("pause");
	return 0;
}