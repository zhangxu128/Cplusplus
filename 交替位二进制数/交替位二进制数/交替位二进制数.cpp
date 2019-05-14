//����һ����������������Ƿ�Ϊ����λ�������������仰˵���������Ķ����������ڵ�����λ��������ȡ�
//ʾ�� 1:
//����: 5
//	��� : True
//	���� :
//	5�Ķ��������� : 101
//		ʾ�� 2 :
//		���� : 7
//		��� : False
//		���� :
//	7�Ķ��������� : 111
//		ʾ�� 3 
//		���� : 11
//		��� : False
//		���� :
//	11�Ķ��������� : 1011
//		ʾ�� 4 :
//		���� : 10
//		��� : True
//		���� :
//	10�Ķ��������� : 1010

#include <iostream>
#include <vector>

using namespace std;

//��һ�� �Ƚ������ת��Ϊ�����������浽������
//�ڶ��� �Ƚ������������������Ƿ���ȼ���
bool hasAlternatingBits(int n) {
	if (n == 1) {
		return true;
	}
	vector<int>v;
	int tmp;
	while (n != 0) {
		tmp = n % 2;
		v.push_back(tmp);
		n /= 2;
	}
	int i = 0, j = 1;
	while (i < v.size() && j < v.size()) {
		if (v[i] == v[j]) {
			return false;
		}
		i++;
		j++;
	}
	return true;
}

int main(void) {

	cout << "����һ����" << endl;
	int n;
	cin >> n;
	if (hasAlternatingBits(n)) {
		cout << "�������һ��������λ������" << endl;
	}
	else {
		cout << "���������һ��������λ������" << endl;
	}
	system("pause");
	return 0;
}