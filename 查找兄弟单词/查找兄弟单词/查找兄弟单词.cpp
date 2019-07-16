//链接：https://www.nowcoder.com/questionTerminal/03ba8aeeef73400ca7a37a5f3370fe68
//来源：牛客网

#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool isBrother(string s1, string s2)
{
	if (s1 == s2)//string重载了全部的六个关系运算符可直接进行比较不用strcmp
	{
		return false;
	}
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	if (s1 == s2)
	{
		return true;
	}
	else return false;
}
int main()
{
	int n;
	while (cin >> n)
	{
		vector<string> v(n);//初始化n个vector向量
		for (int i = 0; i < n; i++)
			cin >> v[i];
		vector<string>b;
		int m;
		string str;
		cin >> str;
		cin >> m;
		for (int i = 0; i < n; i++)
		{
			if (isBrother(str, v[i]))
			{
				b.push_back(v[i]);
			}
		}
		sort(b.begin(), b.end());
		cout << b.size() << endl;
		if (m <= b.size())
		{
			cout << b[m - 1] << endl;
		}
	}
	return 0;
}