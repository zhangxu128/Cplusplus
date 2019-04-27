//题目描述
//合法的括号匹配序列被定义为 :
//1. 空串""是合法的括号序列
//2. 如果"X"和"Y"是合法的序列, 那么"XY"也是一个合法的括号序列
//3. 如果"X"是一个合法的序列, 那么"[X]"也是一个合法的括号序列
//4. 每个合法的括号序列都可以由上面的规则生成
//例如"", "[]", "[][][]", "[[][]]", "[[[[]]]]"都是合法的。
//牛牛现在给出一个括号序列s, 牛牛允许你执行的操作是:在s的开始和结尾处添加一定数量的左括号('[')或者右括号(']')使其变为一个合法的括号匹配序列。牛牛希望你能求出添加最少的括号之后的合法的括号匹配序列是什么。
//输入描述 :
//输入包括一个字符串s, s的长度length(1 ≤ length ≤ 50), s中只包含'['和']'。
//输出描述 :
//输出一个字符串, 表示括号完全匹配的序列。
//示例1
//输入
//][
//输出
//[][]

#include<iostream>
#include<string>
#include<stack>
using namespace std;
void Func2(string &str)
{
	size_t len = str.length();
	stack<char> s;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == '[')
			s.push(str[i]);
		else
		{
			if (!s.empty() && s.top() == '[')
				s.pop();
			else
				s.push(']');
		}
	}
	while (!s.empty())
	{
		if (s.top() == '[')
			str.append("]");
		else
			str.insert(0, "[");
		s.pop();

	}
	return;
}
int main()
{
	string str;
	cin >> str;
	Func2(str);
	cout << str << endl;
	system("pause");
	return 0;
}