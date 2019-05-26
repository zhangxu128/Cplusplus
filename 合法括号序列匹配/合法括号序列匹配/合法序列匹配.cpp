//判断输入的序列是否为合法序列

#include <iostream>
#include <string>

using namespace std;

class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		// write code here
		int x = 0;
		int y = 0;
		for (int i = 0; i < n; i++) {
			if (A[i] == '(') {
				x++;
			}
			else {
				y++;
			}
			if (x < y) {
				return false;
			}
		}
		if (x != y) {
			return false;
		}
		return true;
	}
};

int main(void) {
	
	cout << "输入字符串长度" << endl;
	int n;
	cin >> n;
	cout << "输入字符串" << endl;	
	string s;
	cin >> s;
	Parenthesis p;
	cout << p.chkParenthesis(s,n) << endl;
	system("pause");
	return 0;
}