#include<iostream>
#include<string>
#include<strstream>
using namespace std;
//判断一个数是不是回文数
bool isPalindrome(int x) {
	strstream ss;
	string s;
	ss << x;
	ss >> s;
	string s1 = s;
	reverse(s.begin(), s.end());
	if (s1 == s)
	{
		return true;
	}
	return false;
}


int main()
{
	int num = 0;
	cin >> num;
	bool b = isPalindrome(num);
	cout << b << endl;
	system("pause");
	return 0;
}