//题目描述
//将中缀表达式转为后缀表达式，输入 a + b * c / d - a + f / b 输出 abc*d / +a - fb / +
//要求：语言不限；输入输出均为单个字符串；操作数用单个小写字母表示，操作符只需支持 + -*/ ，按照四则运算顺序确定优先级，不包含括号
//输入描述 :
//一个字符串为合法的中缀表达式
//字符串长度不超过200000
//输出描述 :
//对应的后缀表达式
//示例1
//输入
//
//复制
//a + b * c / d - a + f / b
//输出
//
//复制
//abc*d / +a - fb / +
//
//#include <iostream>
//#include <string>
//#include <stack>
//
//using namespace std;
//int main() {
//	string s, res;
//	cin >> s;
//	if (s.size() == 0) {
//		cout << res;
//		return 0;
//	}
//	stack<char> st;
//	int i = 0;
//	while (i < s.size()) {
//		if (s[i] >= 'a'&&s[i] <= 'z') {
//			res += s[i++];
//		}
//		else if (s[i] == '+' || s[i] == '-') {
//			if (!st.empty()) {
//				res += st.top();
//				st.pop();
//			}
//			st.push(s[i++]);
//		}
//		else if (s[i] == '*' || s[i] == '/') {
//			//st.push(s[i++]);
//			res += s[++i];
//			res += s[i - 1];
//			i++;
//		}
//	}
//	if (!st.empty()) {
//		res += st.top();
//		st.pop();
//	}
//	cout << res;
//	return 0;
//}

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void) {

	string s, res;
	stack<char> stk;

	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		//如果是自没有直接构造字符串
		if (s[i] >= 'a' && s[i] <= 'z') {
			res += s[i];
		}
		//如果是加减号，放入栈中
		else if (s[i] == '+' || s[i] == '-') {
			//如果栈不为空
			if (!stk.empty()) {
				res += stk.top();
				stk.pop();
			}
			stk.push(s[i]);
		}
		//如果是乘除  特殊处理
		else if(s[i] == '*' || s[i] == '/'){
			res += s[++i];
			res += s[i - 1];
		}
	}
	if (!stk.empty()) {
		res += stk.top();
		stk.pop();
	}

	cout << res << endl;

	return 0;
}