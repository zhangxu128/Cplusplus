//��������������������
// xcopy /s c:\ d:\
//��������
// �����ָ�Ϊ�ո�
// ����������Ϊһ������
// ����������

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {

	string s;
	while (getline(cin, s)) {
		vector<string> v;
		string tmp = "";
		for (int i = 0; i < s.size(); i++) {
			
			if (s[i] != ' ') {
				tmp += s[i];
			}
			else if(s[i]==' '){
				v.push_back(tmp);
				tmp = "";
			}
		}
		v.push_back(tmp);
		cout << v.size() << endl;
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << endl;
		}
	}

	system("pause");
	return 0;
}
