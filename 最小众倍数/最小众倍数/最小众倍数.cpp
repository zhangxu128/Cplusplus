#include<iostream>
#include<vector>
using namespace std;

//题目描述
//给定5个正整数, 它们的最小的众倍数是指的能够被其中至少三个数整除的最小正整数。
//给定5个不同的正整数, 请计算输出它们的最小众倍数。
//输入 1 2 3 4 5
//输出 4




//暂时没想出来好办法，只能从1开始网上加，求最小众倍数
int main() {
	int num;
	vector<int> v;
	for (int i = 0; i < 5; i++) {
		cin >> num;
		//将输入近来的数放入容器中，以便后序操作
		v.push_back(num);
	}
	int k = 1;
	int r = 0;
	while (1) {
		if (k%v[0] == 0) {
			r++;
		}
		if (k%v[1] == 0) {
			r++;
		}
		if (k%v[2] == 0) {
			r++;
		}
		if (k%v[3] == 0) {
			r++;
		}
		if (k%v[4] == 0) {
			r++;
		}
		if (r >= 3) {
			cout << k << endl;
			break;
		}
		k++;
		r = 0;
	}
	system("pause");
	return 0;
}