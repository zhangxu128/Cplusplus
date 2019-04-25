//题目描述    由于题目为图片形式，无法粘贴，题为牛客网2018真题之手机号
//输入描述 :
//输出描述:
//示例1
//输入
//5
//13312345678
//18687654324
//18277748494
//15898494958
//45364
//输出
//China Telecom
//China Unicom
//China Mobile Communications
//- 1
//- 1

#include <iostream>
#include <string>
using namespace std;

bool isTrue(string a[], string s)   //判断s属不属于a
{
	if (s.length() != 11)
	{
		return false;
	}
	string temp = s.substr(0, 3);
	for (int i = 0; i < 5; i++)
	{
		if (a[i] == temp)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	string CT[] = { "133","153","180","181","189" };   //中国电信
	string CU[] = { "130","131","155","185","186" };   //中国联通
	string CMC[] = { "135","136","150","182","188" };  //中国移动
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		string temp;
		cin >> temp;
		if (isTrue(CT, temp))
		{
			cout << "China Telecom" << endl;
		}
		else if (isTrue(CU, temp))
		{
			cout << "China Unicom" << endl;
		}
		else if (isTrue(CMC, temp))
		{
			cout << "China Mobile Communications" << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}
	system("pause");
	return 0;
}