//��Ŀ����
//����һ������n����n�ֽ�Ϊ������������֮�ͣ�ʹ����Щ�����ĳ˻���󻯣�����ܹ���õ����ĳ˻���
//���磺
//2 = 1 + 1�����1��
//10 = 3 + 3 + 4�����36��
//�������� :
//����Ϊ1������
//������� :
//���Ϊ1������
//ʾ��1
//����
//10
//���
//36

#include <iostream>
using namespace std;

int getMax(int n) {
	int max = 1;
	int i;
	for (i = n; i >= 4; i -= 3) {
		if (n == 4) {
			max = max * 4;
		}
		else {
			max = max * 3;
		}
	}
	if (i == 3) {
		max = max * 3;
	}
	else if (i == 2) {
		max = max * 2;
	}

	return max;
}

int main(void) {
	int n;
	cin >> n;
	if (n == 1) {
		cout << 0 << endl;
	}
	else if (n == 2) {
		cout << 1 << endl;
	}
	else if (n == 3) {
		cout << 2 << endl;
	}
	else {
		int ret = getMax(n);
		cout << ret << endl;
	}
	system("pause");
	return 0;
}