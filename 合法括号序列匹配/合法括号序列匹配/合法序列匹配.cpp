//�ж�����������Ƿ�Ϊ�Ϸ�����

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
	
	cout << "�����ַ�������" << endl;
	int n;
	cin >> n;
	cout << "�����ַ���" << endl;	
	string s;
	cin >> s;
	Parenthesis p;
	cout << p.chkParenthesis(s,n) << endl;
	system("pause");
	return 0;
}