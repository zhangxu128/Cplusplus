//���������������ַ������������ǵĺͣ��ö����Ʊ�ʾ����
//
//����Ϊ�ǿ��ַ�����ֻ�������� 1 �� 0��
//
//ʾ�� 1:
//
//����: a = "11", b = "1"
//	��� : "100"
//	ʾ�� 2 :
//
//	���� : a = "1010", b = "1011"
//	��� : "10101"

#include <iostream>
#include <string>

using namespace std;

string addBinary(string a, string b) {
	/*  ����ָ��ֱ�ָ��a��b��ĩβ��Ȼ��ÿ��ȡ��һ���ַ���תΪ���֣����޷�ȡ���ַ���0����
	Ȼ�����λcarry����ʼ��Ϊ0�������߼���������2ȡ�༴Ϊ��ǰλ�����֣���2ȡ�̼�Ϊ��ǰ��λ��ֵ��
	�ǵ����Ҫ�ж���carry�����Ϊ1�Ļ���Ҫ�ڽ����ǰ�����һ��1��*/
	string res = "";
	int m = a.size() - 1, n = b.size() - 1, carry = 0;
	while (m >= 0 || n >= 0) {
		int p = m >= 0 ? a[m--] - '0' : 0;
		int q = n >= 0 ? b[n--] - '0' : 0;
		int sum = p + q + carry;
		res = to_string(sum % 2) + res;
		carry = sum / 2;
	}
	return carry == 1 ? "1" + res : res;
}

int main(void) {
	
	string s1, s2;
	cin >> s1 >> s2;
	cout << addBinary(s1, s2) << endl;
	system("pause");
	return 0;
}