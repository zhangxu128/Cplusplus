//���������ַ�����ʽ�ķǸ����� num1 ��num2 ���������ǵĺ͡�
//ע�⣺
//num1 ��num2 �ĳ��ȶ�С�� 5100.
//num1 ��num2 ��ֻ�������� 0 - 9.
//num1 ��num2 ���������κ�ǰ���㡣
//�㲻��ʹ���κ΃Ƚ� BigInteger �⣬ Ҳ����ֱ�ӽ�������ַ���ת��Ϊ������ʽ��


#include <iostream>
#include <string>

using namespace std;


//ģ����ʽ���㷽ʽ���ɣ���������Ҫ������λ
string addStrings(string num1, string num2) {
	int len1 = num1.size();
	int len2 = num2.size();
	string s = "";
	int carry = 0;
	while (len1 > 0 || len2 > 0 || carry != 0) {
		if (len1 > 0) {
			carry += num1[--len1] - '0';
		}
		if (len2 > 0) {
			carry += num2[--len2] - '0';
		}
		s += to_string(carry % 10);
		carry /= 10;
	}
	reverse(s.begin(), s.end());
	return s;
}

int main(void) {

	string s1;
	string s2;	
	cin >> s1 >> s2;
	cout << addStrings(s1, s2) << endl;
	system("pause");
	return 0;
}