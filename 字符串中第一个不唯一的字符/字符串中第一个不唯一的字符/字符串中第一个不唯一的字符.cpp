//����һ���ַ������ҵ����ĵ�һ�����ظ����ַ���������������������������ڣ��򷵻� - 1��
//
//���� :
//
//s = "leetcode"
//���� 0.
//
//s = "loveleetcode",
//���� 2.

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//adaccdcda  aaacccddd
int firstUniqChar(string s) {
	//�Կռ任ʱ��
	if (s.size() == 1) {
		return 0;
	}
	int len = s.size();
	int tong[26] = { 0 };
	for (int i = 0; i < len; i++) {
		tong[s[i] - 'a']++;
	}
	for (int i = 0; i < len; i++) {
		if (tong[s[i]-'a'] == 1) {
			return i;
		}
	}
	return -1;
}

int main(void) {

	cout << "����һ���ַ���" << endl;
	string s;
	cin >> s;
	cout << "�ַ����е�һ����Ψһ ���ַ���λ����" << firstUniqChar(s) << endl;
	
	system("pause");
	return 0;
}