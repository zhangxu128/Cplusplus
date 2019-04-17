#include<iostream>
using namespace std;

//����Ϊһ��������N(1 �� N �� 1, 000, 000)
//�������:
//���һ����С�Ĳ�����ΪFibonacci��"
//ʾ��1
//����
//15
//���
//2


//��쳲���������ֵ
int fib(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1 || n == 2) {
		return 1;
	}
	return fib(n - 1) + fib(n - 2);
}

//������С����
int min(int a, int b) {
	return a = a <= b ? a : b;
}

int main(void) {
	int N;
	cin >> N;
	int ret = 0;
	for (int i = 0; i <= N; i++) {   // ������С����
		if (fib(i) <= N && fib(i + 1) > N) {
			ret = min((N - fib(i)), (fib(i + 1) - N));
			break;
		}
	}
	cout << ret << endl;
	return 0;
}