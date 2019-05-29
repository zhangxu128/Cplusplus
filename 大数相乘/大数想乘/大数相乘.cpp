//�����������ַ�����ʽ��ʾ�ķǸ����� num1 �� num2������ num1 �� num2 �ĳ˻������ǵĳ˻�Ҳ��ʾΪ�ַ�����ʽ��
//ʾ�� 1:
//����: num1 = "2", num2 = "3"
//	��� : "6"
//	ʾ�� 2 :
//	���� : num1 = "123", num2 = "456"
//	��� : "56088"
//	˵��
//	num1 �� num2 �ĳ���С��110��
//	num1 �� num2 ֻ�������� 0 - 9��
//	num1 �� num2 �������㿪ͷ������������ 0 ����
//	����ʹ���κα�׼��Ĵ������ͣ����� BigInteger����ֱ�ӽ�����ת��Ϊ����������

#include <iostream>
#include <string>

using namespace std;

string multiply(string num1, string num2) {
	if (num1 == "0" || num2 == "0")
		return "0";
	int size1 = num1.size(), size2 = num2.size();
	string str(size1 + size2, '0');
	for (int i = size1 - 1; i >= 0; i--) {
		int mulflag = 0;
		int addflag = 0;
		for (int j = size2 - 1; j >= 0; j--) {
			int tmp = (num1[i] - '0') * (num2[j] - '0') + mulflag;
			mulflag = tmp / 10;
			tmp = tmp % 10;
			int tmp2 = str[i + j + 1] - '0' + tmp + addflag;
			str[i + j + 1] = tmp2 % 10 + '0';
			addflag = tmp2 / 10;
		}
		str[i] += mulflag + addflag;
	}
	if (str[0] == '0')
		str = str.substr(1, str.size());
	return str;
}


int main(void) {
	cout << "������������" << endl;
	string s1;
	string s2;
	cin >> s1 >> s2;
	cout << multiply(s1, s2) << endl;
	system("pause");
	return 0;
}