#include<iostream>
#include<string>
#include<strstream>
using namespace std;
//�ж�һ�����ǲ��ǻ�����
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