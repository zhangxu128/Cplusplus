//����һ���Ǹ����� c ����Ҫ�ж��Ƿ������������ a �� b��ʹ�� a2 + b2 = c��
//ʾ��1 :
//����: 5
//	��� : True
//	���� : 1 * 1 + 2 * 2 = 5
//	ʾ��2 :
//	���� : 3
//	��� : False

#include <iostream>

using namespace std;


//����˫ָ�� ���
bool judgeSquareSum(int c,int* ii,int* jj) {
	long i = 0, j = (int)sqrt(c), tmp;
	while (i <= j) {
		tmp = i * i + j * j - c;
		if (tmp == 0) {
			*ii = i;
			*jj = j;
			return true;
		}
		if (tmp > 0) j = j - 1;
		else i = i + 1;
	}
	return false;
}

int main(void){

	cout << "������һ����" << endl;
	int n;
	cin >> n;
	int i, j;
	if (judgeSquareSum(n, &i, &j)) {
		cout << i << "*" << i << "+" << j << "*" << j << "=" << n << endl;
	}
	else {
		cout << "�����޷�����������ƽ���͹���" << endl;
	}
	system("pause");
	return 0;
}