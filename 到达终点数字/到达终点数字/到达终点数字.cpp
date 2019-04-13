#include<iostream>
using namespace std;

//��һ�����޳��������ϣ���վ��0��λ�á��յ���target��λ�á�
//ÿ�������ѡ������������ƶ����� n ���ƶ����� 1 ��ʼ���������� n ����
//���ص����յ���Ҫ����С�ƶ�������
//  ʾ�� 1:
//  ����: target = 3
//	��� : 2
//	���� :
//	��һ���ƶ����� 0 �� 1 ��
//	�ڶ����ƶ����� 1 �� 3 ��
//	ʾ�� 2 :
//	���� : target = 2
//	��� : 3
//	���� :
//	��һ���ƶ����� 0 �� 1 ��
//	�ڶ����ƶ����� 1 �� - 1 ��
//	�������ƶ����� - 1 �� 2 ��


int reachNumber(int target) {
	int sum = 0;
	for (int i = 1; sum != abs(target); i++) {
		if (sum < abs(target)) {
			if ((sum + i) > abs(target)) {
				sum -= i;
			}
			else {
				sum += i;
			}
		}
		if (sum == abs(target)) {
			return i;
		}
	}
	return 0;
}
int main() {
	int n;
	cin >> n;
	cout << reachNumber(n) << endl;
	system("pause");
	return 0;
}