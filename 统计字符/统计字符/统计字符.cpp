#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//��Ŀ����
//����һ��Ӣ���ַ���, ��дһ�δ����ҳ�����ַ��������ȳ������ε��Ǹ�Ӣ���ַ�(��Ҫ���ִ�Сд)��

bool getcount(char c,int k, string s) {
	int count = 1;
	for (int i = k+1; i < s.size(); i++) {
		if (c == s[i]) {
			count++;
			if (count >= 3) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	
	string  s;
	getline(cin, s);
	int i;
	for (i = 0; i < s.size(); i++) {
		if (getcount(s[i],i,s)) {
			break;
		}
	}
	cout << s[i] << endl;
	system("pause");
	return 0;
}