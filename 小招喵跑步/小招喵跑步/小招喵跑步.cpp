//��Ŀ����
//С����ϲ����������������ȥ������������վ�ڵ�n������ֻ��3���߷����ֱ��ǣ�
//1.��������ǰ��һ������n = n + 1
//2.�����������һ��, ��n = n - 1
//3.������ʹ����Ծ����ǰ�����������n = 2 * n
//����С������ԭ�㣬��n = 0������ȥ��x�������С�������������߷���Ҫ���ٲ���

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// �뵽λ��x��
int process(int x) {
	if (x < 2) {
		return x;
	}
	vector<int> dp(x + 1);
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= x; ++i) {
		if (i % 2 == 0) { // ������ // ��Ȼ������
			dp[i] = 1 + min(dp[i - 1], dp[i / 2]);
		}
		else {
			dp[i] = 1 + min(dp[i - 1], 1 + dp[(i + 1) / 2]);
		}
	}
	return dp[x];
}

int main() {
	int x = 0;
	while (cin >> x) {
		cout << process(abs(x)) << endl;
	}
	return 0;
}
