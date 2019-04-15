#include<iostream>

using namespace std;

//����һ�������� N���ҵ������� N �Ķ����Ʊ�ʾ������������ 1 ֮�������롣
//���û������������ 1������ 0 ��
//ʾ�� 1��
//���룺22
//�����2
//���ͣ�
//22 �Ķ������� 0b10110 ��
//�� 22 �Ķ����Ʊ�ʾ�У������� 1��������������� 1 ��
//��һ�������� 1 �У����� 1 ֮��ľ���Ϊ 2 ��
//�ڶ��������� 1 �У����� 1 ֮��ľ���Ϊ 1 ��
//��ȡ��������֮�����ģ�Ҳ���� 2 ��

int binaryGap(int N) {
	int max = 0;
	int first = 0;
	int second = 0;
	int count = 0;
	for (int i = 0; i < 32; i++) {
		if (count == 0) {
			if ((N & 1) == 1) {
				first = i;
				count++;
			}
		}
		else if (count == 1) {
			if ((N & 1) == 1) {
				second = i;
				count++;
				max = second - first;
			}
		}
		else {
			if ((N & 1) == 1) {
				first = second;
				second = i;
				max = max > (second - first) ? max : (second - first);
			}
		}
		N = N >> 1;
	}
	return max;
}

int main(void) {

	int n;
	cin >> n;
	cout << binaryGap(n) << endl;
	system("pause");
	return 0;
}