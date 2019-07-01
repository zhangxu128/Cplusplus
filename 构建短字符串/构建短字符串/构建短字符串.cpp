//题目描述
//给定任意一个较短的子串，和另一个较长的字符串，判断短的字符串是否能够由长字符串中的字符构建出来，且长串中的每个字符只能用一次。
//输入描述 :
//一行数据包括一个较短的字符串S和一个较长的字符串T，用一个空格分隔。保证1<=|S|<=|T|<=100000。
//输出描述 :
//如果短的字符串可以由长字符串中的字符构建出来，输出字符串 “true”，否则输出字符串 "false"。
//示例1
//输入
//a b
//输出
//false
//示例2
//输入
//fj jfiejfiejfie
//输出
//true

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string a, b;
	while (cin >> a >> b)
	{
		bool res = true;
		vector<int> va(256, 0);
		vector<int> vb(256, 0);
		for (int i = 0; i < a.size(); i++)
			va[a[i]] ++;
		for (int i = 0; i < b.size(); i++)
			vb[b[i]] ++;
		for (int i = 0; i < 256; i++)
			if (va[i] > vb[i])
				res = false;
		if (res)
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	system("pause");
	return 0;
}
