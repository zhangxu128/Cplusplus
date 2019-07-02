//题目描述
//给定一个字符串，输出所有指定长度为n的子串，没有则输出 - 1
//输入描述:
//输入第一行一个字符串，如：“1234567890”
//
//输入第二行一个数字是n，如5
//输出描述 :
//输出所有长度为n的子串，如“12345”，“23456”，“34567”，“45678”，“56789”
//示例1
//输入
//
//复制
//123456789
//5
//输出
//
//复制
//12345 23456 34567 45678 56789

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	string str;
	cin >> str >> n;
	if (n > str.length())
		cout << "-1" << endl;
	else
	{
		cout << str.substr(0, n);
		for (int i = 1; i + n <= str.length(); ++i)
			cout << ' ' << str.substr(i, n);
		cout << endl;
	}

	system("pause");
	return 0;
}
