//题目描述
//给定整数n，取若干个1到n的整数可求和等于整数m，编程求出所有组合的个数。比如当n = 6，m = 8时，
//有四种组合：[2, 6], [3, 5], [1, 2, 5], [1, 3, 4]。限定n和m小于120


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