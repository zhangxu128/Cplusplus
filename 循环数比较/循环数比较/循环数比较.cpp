//��Ŀ����
//������������������x��k, ���Ƕ���repeat(x, k)Ϊ��x�ظ�дk���γɵ���, ����repeat(1234, 3) = 123412341234, repeat(20, 2) = 2020.
//ţţ���ڸ���4������x1, k1, x2, k2, ����v1 = (x1, k1), v2 = (x2, k2), �������Ƚ�v1��v2�Ĵ�С��
//�������� :
//�������һ��, һ������4��������x1, k1, x2, k2(1 �� x1, x2 �� 10 ^ 9, 1 �� k1, k2 �� 50), �Կո�ָ�
//������� :
//���v1С��v2���"Less", v1����v2���"Equal", v1����v2���"Greater".
//ʾ��1
//����
//1010 3 101010 2
//���
//Equal

#include<iostream>
#include<string>

using namespace std;

int main() {
	string x1, x2;
	int k1, k2;
	cin >> x1 >> k1 >> x2 >> k2;
	//  handle x1
	string rep_x1 = x1;
	for (int i = 1; i < k1; i++)
		rep_x1 += x1;
	// hanlde x2
	string rep_x2 = x2;
	for (int i = 1; i < k2; i++)
		rep_x2 += x2;
	if (rep_x1.size() == rep_x2.size()) {
		if (rep_x1 == rep_x2) cout << "Equal" << endl;
		else if (rep_x1 < rep_x2) cout << "Less" << endl;
		else cout << "Greater" << endl;
	}
	else if (rep_x1.size() < rep_x2.size()) cout << "Less" << endl;
	else cout << "Greater" << endl;
	return 0;
}