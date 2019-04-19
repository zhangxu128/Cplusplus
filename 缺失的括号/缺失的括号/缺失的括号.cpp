#include <iostream>
#include <string>
#include <stack>

//题目描述
//一个完整的括号字符串定义规则如下 :
//1、空字符串是完整的。
//2、如果s是完整的字符串，那么(s)也是完整的。
//3、如果s和t是完整的字符串，将它们连接起来形成的st也是完整的。
//例如，"(()())", ""和"(())()"是完整的括号字符串，"())(", "()(" 和 ")"是不完整的括号字符串。
//牛牛有一个括号字符串s, 现在需要在其中任意位置尽量少地添加括号, 
//将其转化为一个完整的括号字符串。请问牛牛至少需要添加多少个括号。
//  输入
//  (()(()
//	输出
//	2

using namespace std;

int main() {

	//利用栈的先进后出的特性，将左括号进栈，然后匹配右括号
	string str;
	getline(cin, str);
	stack<char> stk;
	int count = 0;
	for (int i = 0; i < str.size(); i++) {
		if (stk.empty() && str[i] == ')') {
			count++;
		}
		//如果是左括号，进栈
		if(str[i] == '('){
			stk.push(str[i]);
		}
		if(str[i]==')'&& !stk.empty()){
			stk.pop();
		}

	}
	cout << count + stk.size() << endl;
	system("pause");
	return 0;
}