//��Ŀ����
//����һ���ַ������������ָ������Ϊn���Ӵ���û������� - 1
//��������:
//�����һ��һ���ַ������磺��1234567890��
//
//����ڶ���һ��������n����5
//������� :
//������г���Ϊn���Ӵ����硰12345������23456������34567������45678������56789��
//ʾ��1
//����
//
//����
//123456789
//5
//���
//
//����
//12345 23456 34567 45678 56789

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	string str;
	cin >> str >> n;
	if (n > str.length())
		cout << "-1" << endl;
	else
	{
		cout << str.substr(0, n);
		for (int i = 1; i + n <= str.length(); ++i)
			cout << ' ' << str.substr(i, n);
		cout << endl;
	}

	system("pause");
	return 0;
}
