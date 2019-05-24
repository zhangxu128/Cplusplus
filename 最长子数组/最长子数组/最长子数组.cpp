//输入数组个数n
//输入数组元素
//输出最大子数组和
//例如： 3
//       -1 2 1
// 输出  3


#include <iostream>
#include <vector>

using namespace std;

int main(void) {

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	//用等长数组保存到该位置元素和的最大值，然后遍历输出最大值
	int* p = new int[n];
	p[0] = v[0];
	for (int i = 1; i < n; i++) {
		p[i] = v[i] > v[i] + p[i - 1] ? v[i] : v[i] + p[i - 1];
	}
	if (v.size() == 1) {
		cout << v[0] << endl;
	}
	else {
		int max = p[0];
		for (int i = 1; i < n; i++) {
			if (max < p[i]) {
				max = p[i];
			}
		}
		cout << max << endl;
	}
	delete[] p;
	system("pause");
	return 0;
}