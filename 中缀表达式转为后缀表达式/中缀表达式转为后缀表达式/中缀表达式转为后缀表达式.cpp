//��Ŀ����
//����׺���ʽתΪ��׺���ʽ������ a + b * c / d - a + f / b ��� abc*d / +a - fb / +
//Ҫ�����Բ��ޣ����������Ϊ�����ַ������������õ���Сд��ĸ��ʾ��������ֻ��֧�� + -*/ ��������������˳��ȷ�����ȼ�������������
//�������� :
//һ���ַ���Ϊ�Ϸ�����׺���ʽ
//�ַ������Ȳ�����200000
//������� :
//��Ӧ�ĺ�׺���ʽ
//ʾ��1
//����
//
//����
//a + b * c / d - a + f / b
//���
//
//����
//abc*d / +a - fb / +
//
//#include <iostream>
//#include <string>
//#include <stack>
//
//using namespace std;
//int main() {
//	string s, res;
//	cin >> s;
//	if (s.size() == 0) {
//		cout << res;
//		return 0;
//	}
//	stack<char> st;
//	int i = 0;
//	while (i < s.size()) {
//		if (s[i] >= 'a'&&s[i] <= 'z') {
//			res += s[i++];
//		}
//		else if (s[i] == '+' || s[i] == '-') {
//			if (!st.empty()) {
//				res += st.top();
//				st.pop();
//			}
//			st.push(s[i++]);
//		}
//		else if (s[i] == '*' || s[i] == '/') {
//			//st.push(s[i++]);
//			res += s[++i];
//			res += s[i - 1];
//			i++;
//		}
//	}
//	if (!st.empty()) {
//		res += st.top();
//		st.pop();
//	}
//	cout << res;
//	return 0;
//}

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void) {

	string s, res;
	stack<char> stk;

	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		//�������û��ֱ�ӹ����ַ���
		if (s[i] >= 'a' && s[i] <= 'z') {
			res += s[i];
		}
		//����ǼӼ��ţ�����ջ��
		else if (s[i] == '+' || s[i] == '-') {
			//���ջ��Ϊ��
			if (!stk.empty()) {
				res += stk.top();
				stk.pop();
			}
			stk.push(s[i]);
		}
		//����ǳ˳�  ���⴦��
		else if(s[i] == '*' || s[i] == '/'){
			res += s[++i];
			res += s[i - 1];
		}
	}
	if (!stk.empty()) {
		res += stk.top();
		stk.pop();
	}

	cout << res << endl;

	return 0;
}