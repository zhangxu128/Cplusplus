#include<iostream>
#include<string>
using namespace std;

//×óÐý×Ö·û´®
class Solution {
public:
	//×óÐý×Ö·û´®
	string LeftRotateString(string str, int n) {
		if (str.size() == 0) {
			return str;
		}
		string s;
		if (n == 0) {
			return str;
		}
		for (int i = n % str.size(); i < str.size(); i++) {
			s.push_back(str[i]);
		}
		if (s.size() < str.size()) {
			for (int i = 0; i < n % str.size(); i++) {
				s.push_back(str[i]);
			}
		}
		return s;
	}
	void print(string s)
	{
		for (int i = 0; i < s.size(); i++) {
			cout << s[i] << " ";
		}
		cout << endl;
	}
};

int main() {

	string str = "abcdefg";
	int n = 0;
	cin >> n;
	Solution ret;
	string s = ret.LeftRotateString(str,n);
	ret.print(s);
	system("pause");
	return 0;
}