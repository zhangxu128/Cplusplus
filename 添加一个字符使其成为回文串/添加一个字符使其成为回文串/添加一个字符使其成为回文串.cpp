
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPa(const string& s) {
	string r = s;
	reverse(r.begin(), r.end());
	return r == s;
}
//如果可以添加一个字母成为回文串，
//那么原字符串或者除去头部的字符串或者除去尾部的字符串一定是回文串！
int main() {
	string str;
	cin >> str;
	string str_0(str.begin() + 1, str.end());
	string str_1(str.begin(), str.end() - 1);
	string ans = "YES";
	if (str != "" && !isPa(str) && !isPa(str_0) && !isPa(str_1)) {
		ans = "NO";
	}
	cout << ans << endl;
	system("pause");
	return 0;
}
