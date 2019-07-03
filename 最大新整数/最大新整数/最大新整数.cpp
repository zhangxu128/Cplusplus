//输入描述:
//一行由正整数组成的数字字符串，和一个正整数 K，两个数据用空格隔开，如：1432219 3。
//字符串长度不超过2000，K <= 2000。
//输出描述 :
//移除 K 位后可能的最大的数字字符串。
//如 1432219 移除 1, 2, 1 这 3 个数字后得到 4329，为所有可能中的最大值。
//示例1
//输入
//
//1432219 3
//输出
//
//4329

#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;
int main(void) {
	string s;
	int k;
	cin >> s >> k;
	stack<char>stk;
	for (int i = 0; i < s.size(); i++) {
		while ((!stk.empty()) && stk.top() < s[i] && k) {
			stk.pop();
			k--;
		}
		stk.push(s[i]);
	}
	while (k--)stk.pop();
	string res;
	while (!stk.empty()) {
		res += stk.top();
		stk.pop();
	}
	reverse(res.begin(), res.end());
	int i = 0;
	while (i < res.size() && res[i] == '0')i++;
	cout << res.substr(i) << endl;
	system("pause");
	return 0;
}