#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//��Ŀ����
//���һ������ֻ�ܱ�1���Լ�����, �ͳ��������������
//���һ�������ŷ��Ŷ���һ��, �ͳ�Ϊ������ǻ�����������:6, 66, 606, 6666
//���һ�����ּ�������Ҳ�ǻ�����, �ͳ�������ǻ�������
//ţţ���ڸ���һ������[L, R], ϣ���������������������ж��ٸ�����������
//�������� :
//�������һ��, һ��������������(1 �� L �� R �� 1000)


//�ж�������ǲ�������
bool isprime(int n) {
	if (n == 1)return false;
	int i;
	for (i = 2; i <= sqrt(n); i++) {
		if (n%i == 0) {
			return false;
		}
	}

	//�ж�������ǲ��ǻ�����
	int sum = 0;
	int k = n;
	while (k != 0) {
		int tmp = k % 10;
		sum = sum * 10 + tmp;
		k /= 10;
	}
	if (n == sum) {
		return true;
	}
	return false;
}

int main() {
	int L, R,count = 0;
	cin >> L >> R;
	for (int i = L; i <= R; i++) {
		if (isprime(i)) {
			count++;
		}
	}
	cout << count << endl;
	system("pause");
	return 0;
}