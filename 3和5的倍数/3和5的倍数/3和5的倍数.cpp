//��Ŀ����
//��������г�10��������3��5�ı��������ǽ��õ�3��5��6��9����Щ���ĺ���23����n��������3��5�ı����ĺ͡�
//�������� :
//����n��n������2000
//������� :
//���n����3��5�����ĺ�


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
		for (int i = 3; i < n; i++) {
			if (i % 3 == 0 || i % 5 == 0) {
				sum += i;
			}
		}
		cout << sum << endl;
	}

	system("pause");
	return 0;
}