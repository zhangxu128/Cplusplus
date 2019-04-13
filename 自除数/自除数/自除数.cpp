#include<iostream>
#include<vector>
using namespace std;

//自除数 是指可以被它包含的每一位数除尽的数。
//例如，128 是一个自除数，因为 128 % 1 == 0，128 % 2 == 0，128 % 8 == 0。
//还有，自除数不允许包含 0 。
//给定上边界和下边界数字，输出一个列表，列表的元素是边界（含边界）内所有的自除数。
//示例 1：
//输入：
//上边界left = 1, 下边界right = 22
//输出：[1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
//注意：
//每个输入参数的边界满足 1 <= left <= right <= 10000。

class Solution {
public:
	bool isitdiv(int n) {    //判断这个数是不是自除数
		if (n > 0 && n < 10) {
			return true;
		}
		int k = n;
		while (k != 0) {
			int t = k % 10;    //22   2
			if (t == 0) {
				return false;
			}
			if (n % t == 0) {
				k /= 10; //   2
			}
			else {
				return false;
			}
		}
		return true;
	}
	vector<int> selfDividingNumbers(int left, int right) {
		vector<int> v;
		for (int i = left; i <= right; i++) {   //若是自除数则放入容器中
			if (isitdiv(i)) {
				v.push_back(i);
			}
		}
		return v;
	}
};
int main(void) {
	vector<int>v;
	int left = 1;
	int right = 22;
	Solution s;
	v = s.selfDividingNumbers(left, right);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}