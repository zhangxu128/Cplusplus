//��Ŀ����
//��������n��ȡ���ɸ�1��n����������͵�������m��������������ϵĸ��������統n = 6��m = 8ʱ��
//��������ϣ�[2, 6], [3, 5], [1, 2, 5], [1, 3, 4]���޶�n��mС��120


#include <iostream>

using namespace std;

int main() {
	int n, m;
	int c[120][120] = { {0} };
	c[1][1] = 1;
	cin >> n >> m;
	for (int i = 2; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (i < j)
				c[i][j] = c[i - 1][j] + c[i - 1][j - i];
			else if (i == j)
				c[i][j] = c[i - 1][j] + 1;
			else
				c[i][j] = c[i - 1][j];
		}
	}
	cout << c[n][m];
	system("pause");
	return 0;
}