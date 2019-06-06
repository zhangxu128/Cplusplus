#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	string s1;
	string s2;
	while (cin >> s1 >> s2) {
		int len1 = s1.size();
		int len2 = s2.size();
		string s = "";
		int carry = 0;
		while (len1 > 0 || len2 > 0 || carry != 0) {

			if (len1 > 0) {
				carry += s1[--len1] - '0';
			}
			if (len2 > 0) {
				carry += s2[--len2] - '0';
			}

			s += to_string(carry % 10);
			carry /= 10;
		}
		reverse(s.begin(), s.end());
		cout << s << endl;
	}
	return 0;
}