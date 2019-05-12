#include <iostream>
#include <string>

using namespace std;

//����һ������������ת��Ϊ7���ƣ������ַ�����ʽ�����
//
//ʾ�� 1:
//
//����: 100
//	��� : "202"
//	ʾ�� 2 :
//
//	���� : -7
//	��� : "-10"

string convertToBase7(int num) {
	
	string s = "";
	bool flag = false;
	if (num < 0) {
		num = -num;
		flag = true;
	}
	
	while (num != 0) {
		int tmp = num % 7;
		s += to_string(tmp);
		num /= 7;
	}
	reverse(s.begin(), s.end());
	if (flag) {
		s = "-" + s;
	}
	return s;
}

int main(void) {

	cout << "������һ������" << endl;
	int n;
	cin >> n;
	string s = convertToBase7(n);
	cout << "ת��Ϊ�߽���Ϊ:" << s << endl;
	system("pause");
	return 0;
}