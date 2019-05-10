#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
//�ڹ�������У���ע�����ִ�Сд������ "Aa" ���ܵ���һ�������ַ�����
//ע�� :
//�����ַ����ĳ��Ȳ��ᳬ�� 1010��
//ʾ�� 1 :
//	���� :
//	"abccccdd"
//	��� :
//	7
//	���� :
//	���ǿ��Թ������Ļ��Ĵ���"dccaccd", ���ĳ����� 7��

using namespace std;

//����ջ������ƥ���ַ�
int longestPalindrome(string s) {
	if (s.size() == 1) {
		return 1;
	}
	sort(s.begin(), s.end());
	int cnt = 0;
	stack<char> stk;
	stk.push(s[0]);
	for (int i = 1; i < s.size(); i++) {
		if (!stk.empty()) {
			char temp = stk.top();
			if (s[i] != temp) {
				stk.push(s[i]);
			}
			else {
				stk.pop();
				cnt += 2;
			}
		}
		else {
			stk.push(s[i]);
		}
		
	}
	if (stk.size()>0) {
		return cnt + 1;
	}
	return cnt;
}

int main(void) {

	cout << "����һ���ַ���" << endl;
	string s;
	cin >> s;
	cout << "���Թ�����Ļ��Ĵ��ĸ�����" << longestPalindrome(s) << endl;
	system("pause");
	return 0;
}