#include <string>
#include <iostream>
using namespace std;

//��Ŀ����
//����һ��ʮ������M���Լ���Ҫת���Ľ�����N����ʮ������Mת��ΪN������
//�������� :
//����Ϊһ�У�M(32λ����)��N(2 �� N �� 16)���Կո������
//������� :
//Ϊÿ������ʵ�����ת���������ÿ�����ռһ�С����N����9��
//���Ӧ�����ֹ���ο�16���ƣ����磬10��A��ʾ���ȵȣ�
int main() {
	string s = "", table = "0123456789ABCDEF";
	int m, n;
	cin >> m >> n;
	while (m) {
		if (m < 0) {
			m = -m;
			cout << "-";
		}
		s = table[m%n] + s;
		m /= n;
	}
	cout << s << endl;
	system("pause");
	return 0;
}