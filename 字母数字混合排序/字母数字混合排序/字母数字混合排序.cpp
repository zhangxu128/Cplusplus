#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//��Ŀ����
//����һ���ַ�����������[0 - 9]��Сд��ĸ[a - z]��Ҫ�����ִ�С������ĸ��a��z����
//������������������ĸ����
//�������� :
//һ���ַ�
//������� :
//�����������һ���ַ�
//ʾ��1
//����
//a31bz
//���
//abz13

int main() {
	string str;
	cin >> str;
	sort(str.begin(), str.end());
	int temp = 0;//������ĸ��ʼ���±�
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			temp = i;
			break;
		}
	}
	string s;
	for (int i = temp; i < str.size(); i++) {
		s.push_back(str[i]);
	}
	for (int i = 0; i < temp; i++) {
		s.push_back(str[i]);
	}
	cout << s << endl;
	system("pause");
	return 0;
}