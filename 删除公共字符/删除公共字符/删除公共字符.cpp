#include<iostream>
#include <string>
#include<algorithm>


using namespace std;
//题目描述
//输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。
//例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”
//输入描述 :
//每个测试输入包含2个字符串
//输出描述 :
//输出删除后的字符串


string delstr(string s1, string s2) {

	for (int i = 0; i < s2.size(); i++)
	{
		int index;
		while ((index = s1.find(s2[i])) != -1)
		{
			s1.erase(index, 1);
		}
	}
	return s1;
}
int main(void) {


	string s1;
	getline(cin, s1);
	string s2;
	getline(cin, s2);
	string s = delstr(s1, s2);
	cout << s << endl;
	system("pause");
	return 0;
}