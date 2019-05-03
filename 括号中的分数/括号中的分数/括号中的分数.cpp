//����һ��ƽ�������ַ��� S�����������������ַ����ķ�����
//() �� 1 �֡�
//AB �� A + B �֣����� A �� B ��ƽ�������ַ�����
//(A) �� 2 * A �֣����� A ��ƽ�������ַ�����
//ʾ�� 1��
//���룺 "()"
//����� 1
//ʾ�� 2��
//���룺 "(())"
//����� 2
//ʾ�� 3��
//���룺 "(()(()))"
//����� 6
//��ʾ��
//S ��ƽ�������ַ�������ֻ����(��) ��
//2 <= S.length <= 50

#include <iostream>
#include <string>
using namespace std;


int scoreOfParentheses(string S) {
	int res = 0, l = 0;
	for (int i = 0; i < S.length(); ++i) {
		if (S[i] == '(') l++;
		else l--;
		if (S[i] == ')' && S[i - 1] == '(') res += 1 << l;
	}
	return res;
}

int main(void) {

	string s;
	cin >> s;
	int count = scoreOfParentheses(s);
	cout << count << endl;
	system("pause");
	return 0;
}