//题目描述
//小Q得到一个神奇的数列 : 1, 12, 123, ...12345678910, 1234567891011...。
//	并且小Q对于能否被3整除这个性质很感兴趣。
//	小Q现在希望你能帮他计算一下从数列的第l个到第r个(包含端点)有多少个数可以被3整除。
//	输入描述 :
//输入包括两个整数l和r(1 <= l <= r <= 1e9), 表示要求解的区间两端。
//输出描述 :
//输出一个整数, 表示区间内能被3整除的数字个数。
//示例1
//输入
//2 5
//输出
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