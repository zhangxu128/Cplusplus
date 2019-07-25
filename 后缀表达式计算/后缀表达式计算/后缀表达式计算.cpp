#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
			string s;
			stack<int> stk;
			
			getline(cin, s);
			for (int i = 0; i < s.size(); i++) {
				if (s[i] >= '0' && s[i] <= '9') {
					stk.push(s[i] - '0');
				}
				else if (s[i] == '+') {
					int left = stk.top();
					stk.pop();
					int right = stk.top();
					stk.pop();
					stk.push(left + right);
				}
				else if (s[i] == '-') {
					int left = stk.top();
					stk.pop();
					int right = stk.top();
					stk.pop();
					stk.push(left - right);
				}
				else if (s[i] == '*') {
					int left = stk.top();
					stk.pop();
					int right = stk.top();
					stk.pop();
					stk.push(left * right);
				}
				else if (s[i] == '/') {
					int left = stk.top();
					stk.pop();
					int right = stk.top();
					stk.pop();
					stk.push(left / right);
				}
			}
			if(!stk.empty())
				cout << stk.top() << endl;
	}
	system("pause");
	return 0;
}