#include<iostream>
#include<string>
#include<stack>
using namespace std;

//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
//
//有效字符串需满足：
//
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//注意空字符串可被认为是有效字符串。

bool isValid(string s) {
	if (s.empty())
	{
		return true;
	}
	if (s.size() % 2 != 0)
	{
		return false;
	}
	stack<char> c;
	if (s[0] == ')' || s[0] == ']' || s[0] == '}')return false;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
		{
			c.push(s[i]);
		}
		else if((s[i]==')'&&c.top()=='(') || (s[i] == ']'&&c.top() == '[') || (s[i] == '}'&&c.top() == '{'))
		{
			c.pop();
		}
		else
		{
			return false;
		}
	}
	if (c.empty()) {
		return true;
	}
	return false;
}

int main()
{
	string s;
	cin >> s;
	cout << isValid(s) << endl;
	system("pause");
	return 0;
}