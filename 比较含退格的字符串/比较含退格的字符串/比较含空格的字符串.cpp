//���� S �� T �����ַ����������Ƿֱ����뵽�հ׵��ı��༭����
//�ж϶����Ƿ���ȣ������ؽ���� # �����˸��ַ���
//ʾ�� 1��
//���룺S = "ab#c", T = "ad#c"
//�����true
//���ͣ�S �� T ������ ��ac����
//ʾ�� 2��
//���룺S = "ab##", T = "c#d#"
//�����true
//���ͣ�S �� T ������ ������
//ʾ�� 3��
//���룺S = "a##c", T = "#a#c"
//�����true
//���ͣ�S �� T ������ ��c����
//ʾ�� 4��
//���룺S = "a#c", T = "b"
//�����false
//���ͣ�S ���� ��c������ T ��Ȼ�� ��b����
//��ʾ��
//1 <= S.length <= 200
//1 <= T.length <= 200
//S �� T ֻ����Сд��ĸ�Լ��ַ� '#'��

#include <iostream>
#include <string>
#include <stack>

using namespace std;


bool backspaceCompare(string S, string T) {
	stack<char> stack1,stack2;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] != '#') {
			stack1.push(S[i]);
		}
		if (S[i] == '#' && !stack1.empty()) {
			stack1.pop();
		}
	}
	for (int i = 0; i < T.size(); i++) {
		if (S[i] != '#') {
			stack2.push(S[i]);
		}
		if (S[i] == '#' && !stack2.empty()) {
			stack2.pop();
		}
	}
	if (stack1 == stack2) {
		return true;
	}
	return false;
}

int main() {


	string s;
	string t;
	cin >> s >> t;

	if (backspaceCompare(s, t)) {
		cout << true << endl;
	}
	else {
		cout << false << endl;
	}
	system("pause");
	return 0;
}
