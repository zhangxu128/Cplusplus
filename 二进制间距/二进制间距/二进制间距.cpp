#include<iostream>

using namespace std;

//给定一个正整数 N，找到并返回 N 的二进制表示中两个连续的 1 之间的最长距离。
//如果没有两个连续的 1，返回 0 。
//示例 1：
//输入：22
//输出：2
//解释：
//22 的二进制是 0b10110 。
//在 22 的二进制表示中，有三个 1，组成两对连续的 1 。
//第一对连续的 1 中，两个 1 之间的距离为 2 。
//第二对连续的 1 中，两个 1 之间的距离为 1 。
//答案取两个距离之中最大的，也就是 2 。

int binaryGap(int N) {
	int max = 0;
	int first = 0;
	int second = 0;
	int count = 0;
	for (int i = 0; i < 32; i++) {
		if (count == 0) {
			if ((N & 1) == 1) {
				first = i;
				count++;
			}
		}
		else if (count == 1) {
			if ((N & 1) == 1) {
				second = i;
				count++;
				max = second - first;
			}
		}
		else {
			if ((N & 1) == 1) {
				first = second;
				second = i;
				max = max > (second - first) ? max : (second - first);
			}
		}
		N = N >> 1;
	}
	return max;
}

int main(void) {

	int n;
	cin >> n;
	cout << binaryGap(n) << endl;
	system("pause");
	return 0;
}