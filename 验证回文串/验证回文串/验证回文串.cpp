#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
//说明：本题中，我们将空字符串定义为有效的回文串。
//  示例 1:
//  输入: "A man, a plan, a canal: Panama"
//	输出 : true
//	示例 2 :
//	输入 : "race a car"
//	输出 : false

//验证回文串
bool isPalindrome(string s) {
	string str = s;
	int x = 0;
	int y = str.length() - 1;
	int flag = 0;
	while (x < y) {
		if (!((str[x] >= 'a'&&str[x] <= 'z') || (str[x] >= 'A'&&str[x] <= 'Z') || (str[x] >= '0'&&str[x] <= '9'))) {//不是数字或者
			x++;
			continue;
		}
		if (!((str[y] >= 'a'&&str[y] <= 'z') || (str[y] >= 'A'&&str[y] <= 'Z') || (str[y] >= '0'&&str[y] <= '9'))) {//不是数字或者
			y--;
			continue;
		}
		if (str[x] >= 'a'&&str[x] <= 'z') {
			str[x] -= 32;
		}
		if (str[y] >= 'a'&&str[y] <= 'z') {
			str[y] -= 32;
		}
		if (str[x] != str[y]) {
			return false;
		}
		x++;
		y--;
	}
	return true;
}


int main()
{
	string str;
	cin >> str;
	cout << isPalindrome(str) << endl;
	system("pause");
	return 0;
}