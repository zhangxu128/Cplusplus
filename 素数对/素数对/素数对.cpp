#include<iostream>

using namespace std;

//��Ŀ����
//����һ������������д��������ж��ٶ������ĺ͵���������������������������������ֵС��1000��
//�磬����Ϊ10, ����Ӧ��������Ϊ2�����������������ĺ�Ϊ10, �ֱ�Ϊ(5, 5), (3, 7)��


//˼·����������2��n֮�������
//���������ȥĳ���������ж���һ�����ǲ�������

bool isprime(int num,int n) {
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	int count = 0;
	for (int i = 2; i <= n/2; i++) {
		if (isprime(i, n) && isprime(n-i,n)) {
			count++;
		}
	}
	cout << count << endl;
	system("pause");
	return 0;
}