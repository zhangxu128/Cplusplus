//���������ַ�����ɾ����һ���ַ����еڶ����ַ���������Ԫ��
//
//

#include <iostream>
#include <string>

using namespace std;

//˼·��ɾ���Ļ��ȽϺķѴ��ۣ����ײ��������Ի������鷽��
//      �����Ҫ������hashӳ�䣬���ַ���2�е�Ԫ��ӳ�䵽����
//      ����s1������Ϊ0��λ�����鼴�ɡ���
int main() {

	string s1;
	string s2;
	getline(cin,s1);
	getline(cin, s2);

	char hashtable[256] = { 0 };
	//ӳ��
	for (int i = 0; i < s2.size(); i++) {
		hashtable[s2[i]]++;
	}
	
	string s = "";
	//����
	for (int i = 0; i < s1.size(); i++) {
		if (hashtable[s1[i]] == 0) {
			s += s1[i];
		}
	}
	cout << s << endl;
	system("pause");
	return 0;
}