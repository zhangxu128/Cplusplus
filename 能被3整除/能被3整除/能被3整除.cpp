//��Ŀ����
//СQ�õ�һ����������� : 1, 12, 123, ...12345678910, 1234567891011...��
//	����СQ�����ܷ�3����������ʺܸ���Ȥ��
//	СQ����ϣ�����ܰ�������һ�´����еĵ�l������r��(�����˵�)�ж��ٸ������Ա�3������
//	�������� :
//���������������l��r(1 <= l <= r <= 1e9), ��ʾҪ�����������ˡ�
//������� :
//���һ������, ��ʾ�������ܱ�3���������ָ�����
//ʾ��1
//����
//2 5
//���
//3

#include <iostream>

using namespace std;

int main(void) {
	int left = 0;
	int right = 0;
	cin >> left >> right;
	int dif = right - left + 1;
	int cnt = 0;
	if (dif % 3 == 0) {
		cout << dif / 3 * 2 << endl;
	}
	else if (dif % 3 == 1) {
		if (right % 3 != 1) {
			cnt++;
		}
		cout << dif / 3 * 2 + cnt;
	}
	else {
		if (dif % 3 == 2) {
			if (right % 3 == 2) {
				cnt++;
			}
			if (right % 3 == 0) {
				cnt++;
			}
		}
		cout << dif / 3 * 2 + cnt;
	}
	system("pause");
	return 0;
}