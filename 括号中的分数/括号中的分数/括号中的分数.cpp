//给定一个平衡括号字符串 S，按下述规则计算该字符串的分数：
//() 得 1 分。
//AB 得 A + B 分，其中 A 和 B 是平衡括号字符串。
//(A) 得 2 * A 分，其中 A 是平衡括号字符串。
//示例 1：
//输入： "()"
//输出： 1
//示例 2：
//输入： "(())"
//输出： 2
//示例 3：
//输入： "(()(()))"
//输出： 6
//提示：
//S 是平衡括号字符串，且只含有(和) 。
//2 <= S.length <= 50

#include <iostream>
#include <string>
using namespace std;


int scoreOfParentheses(string S) {
	int res = 0, l = 0;
	for (int i = 0; i < S.length(); ++i) {
		if (S[i] == '(') l++;
		else l--;
		if (S[i] == ')' && S[i - 1] == '(') res += 1 << l;
	}
	return res;
}

int main(void) {

	string s;
	cin >> s;
	int count = scoreOfParentheses(s);
	cout << count << endl;
	system("pause");
	return 0;
}