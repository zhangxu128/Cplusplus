#include<iostream>

using namespace std;

//���üӼ��˳����������ĺ�
int Add(int num1, int num2) {
	while (num2 != 0) {
		int sum = num1 ^ num2;
		int carray = (num1 & num2) << 1;
		num1 = sum;
		num2 = carray;
	}
	return num1;
}

//����������൱��ÿһλ��ӣ��������ǽ�λ��
//���������룬������һλ���൱����ý�λ��
//�����������Ľ�����

int main()
{
	cout << Add(3, -1) << endl;
	system("pause");
	return 0;
}