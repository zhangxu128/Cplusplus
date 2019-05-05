#include <iostream>
#include <cmath>

using namespace std;

//��Ŀ����
//��Pi��ʾ��i�����������θ�����������M <= N <= 10000��
//�����PM��PN������������
//�������� :
//������һ���и���M��N������Կո�ָ���
//������� :
//�����PM��PN������������ÿ10������ռ1�У�
//����Կո�ָ�������ĩ�����ж���ո�
//�������� :
//5 27
//������� :
//	11 13 17 19 23 29 31 37 41 43
//	47 53 59 61 67 71 73 79 83 89
//	97 101 103

//˼·���������M��������Ȼ��ʼ�������

bool isprime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {

	int m, n;
	cin >> m >> n;

	int cnt = 0;
	int i = 2;
	int count = 0;
	while (1) {
		if (isprime(i)) {
			cnt++;
			if (cnt >= m && cnt <= n) {
				count++;
				if (count <= 9) {
					cout << i << " ";
				}
				if (count == 10) {
					cout << i << endl;
					count = 0;
				}
			}
			if (cnt > n) {
				break;
			}

		}
		i++;
	}
	cout << endl;
	system("pause");
	return 0;
}