//ͨ���ͨ����ָ �� *
// �������ƥ��һ���ַ�
// * �����ƥ��0�������ַ�
// ����һ������ͨ������ַ���
// ����һ���Ƚ��ַ���
// �жϸ��ַ����Ƿ����ͨ���ƥ�����


#include <iostream>
#include <string>

using namespace std;

bool issame(const string& s1, const string& s2) {
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] == '?' && ((s2[i] >= '0'&& s2[i] <= '9') || (s2[i] >= 'a'&& s2[i] <= 'z') ||
			(s2[i] >= 'A'&& s2[i] <= 'Z'))) {
			continue;
		}
		else if (s1[i] == '*' && i == s1.size() - 1) {
			for (int j = i; j < s2.size(); j++) {
				if ((s2[j] >= '0'&& s2[j] <= '9') || (s2[j] >= 'a'&& s2[j] <= 'z') ||
					(s2[j] >= 'A'&& s2[j] <= 'Z')) {
					continue;
				}
				else {
					return false;
				}
			}
		}
		else if (s1[i] == '*' && i != s1.size() - 1) {
			if ((s2[i] >= '0'&& s2[i] <= '9') || (s2[i] >= 'a'&& s2[i] <= 'z') ||
				(s2[i] >= 'A'&& s2[i] <= 'Z')) {
				continue;
			}
			else {
				return false;
			}
		}
		else if (s1[i] == s2[i]) {
			continue;
		}
		else {
			return false;
		}
	}
	return true;
}

int main(void) {
	string s1;
	string s2;
	while (cin >> s1 >> s2) {
		if (issame(s1, s2)) {
			cout << "true" << endl;
		}
		else {
			cout << "false" << endl;
		}
	}
	return 0;
}