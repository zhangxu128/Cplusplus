//�̵�涨��������ƿ���Ի�һƿ��ˮ
//������n����ƿ�������Ի���ƿ��ˮ

#include <iostream>

using namespace std;

int main(void) {
	
	int n;
	while (cin >> n) {
		if (n < 3) {
			cout << 0 << endl;
			continue;
		}
		int sum = 0;
		// ��ƿ��
		int emp = n;
		int drink;
		while (emp >= 3) {
			drink = emp / 3;
			sum += drink;
			emp = emp - drink * 3 + drink;
		}
		if (emp == 2) {
			sum += 1;
		}
		cout << sum << endl;
	}

	system("pause");
	return 0;
}