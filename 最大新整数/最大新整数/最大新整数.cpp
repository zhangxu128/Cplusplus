//��������:
//һ������������ɵ������ַ�������һ�������� K�����������ÿո�������磺1432219 3��
//�ַ������Ȳ�����2000��K <= 2000��
//������� :
//�Ƴ� K λ����ܵ����������ַ�����
//�� 1432219 �Ƴ� 1, 2, 1 �� 3 �����ֺ�õ� 4329��Ϊ���п����е����ֵ��
//ʾ��1
//����
//
//1432219 3
//���
//
//4329

#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;
int main(void) {
	string s;
	int k;
	cin >> s >> k;
	stack<char>stk;
	for (int i = 0; i < s.size(); i++) {
		while ((!stk.empty()) && stk.top() < s[i] && k) {
			stk.pop();
			k--;
		}
		stk.push(s[i]);
	}
	while (k--)stk.pop();
	string res;
	while (!stk.empty()) {
		res += stk.top();
		stk.pop();
	}
	reverse(res.begin(), res.end());
	int i = 0;
	while (i < res.size() && res[i] == '0')i++;
	cout << res.substr(i) << endl;
	system("pause");
	return 0;
}