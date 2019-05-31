#include <iostream>
#include <vector>

using namespace std;


//直接将第二个数字的二进制直接插入到第一个数字的二进制中即可。

class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		// write code here
		vector<int> v1;
		vector<int> v2;
		for (int i = 0; i < 32; i++) {
			int tmp = (n >> i) & 1;
			int tmp1 = (m >> i) & 1;
			v1.push_back(tmp);
			v2.push_back(tmp1);
		}
		
		int k = 0;
		for (int a = j; a <= i; a++, k++) {
			v1[a] = v2[k];
		}
		int sum = 0;
		for (int i = 0; i < v1.size(); i++) {
			sum = sum + pow(2, i)*v1[i];
		}
		return sum;
	}
};

int main(void) {
	int m, n, j, i;
	while (cin >> m >> n >> j >> i) {
		BinInsert b;
		cout << b.binInsert(m, n, j, i) << endl;;
	}
	system("pause");
	return 0;
}