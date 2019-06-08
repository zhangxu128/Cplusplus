//根据逆波兰表示法，求表达式的值。
//有效的运算符包括  + , -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
//说明：
//整数除法只保留整数部分。
//给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
//  示例 1
//  输入 : ["2", "1", "+", "3", "*"]
//	输出 : 9
//	解释 : ((2 + 1) * 3) = 9
//	示例 2：
//
//	输入 : ["4", "13", "5", "/", "+"]
//	输出 : 6
//	解释 : (4 + (13 / 5)) = 6
//	示例 3：
//
//	输入 : ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
//	输出 : 22
//	解释 :
//	((10 * (6 / ((9 + 3) * -11))) + 17) + 5
//	= ((10 * (6 / (12 * -11))) + 17) + 5
//	= ((10 * (6 / -132)) + 17) + 5
//	= ((10 * 0) + 17) + 5
//	= (0 + 17) + 5
//	= 17 + 5
//	= 22


#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int evalRPN(vector<string>& tokens) {
	stack<int> s;
	for (int i = 0; i < tokens.size(); i++) {
		if (tokens[i][0] >= '0' && tokens[i][0] <= '9' || tokens[i].size() > 1 && tokens[i][0] == '-') {
			s.push(atoi(tokens[i].c_str()));
		}
		else {
			int b = s.top(); s.pop();
			int a = s.top(); s.pop();
			switch (tokens[i][0]) {
			case '+':s.push(a + b); break;
			case '-':s.push(a - b); break;
			case '*':s.push(a*b); break;
			case '/':s.push(a / b); break;
			}
		}
	}
	return s.top();
}

int main(void) {
	string s;
	vector<string>v;
	int n;
	cout << "输入数组大小" << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}
	cout << evalRPN(v) << endl;
	system("pause");
	return 0;
}