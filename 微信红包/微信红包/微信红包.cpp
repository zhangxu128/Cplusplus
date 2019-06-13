//春节期间小明使用微信收到很多个红包，非常开心。在查看领取红包记录时发现，
//某个红包金额出现的次数超过了红包总数的一半。请帮小明找到该红包金额。写出具体算法思路和代码实现，
//要求算法尽可能高效。
//给定一个红包的金额数组gifts及它的大小n，请返回所求红包的金额。
//若没有金额超过总数的一半，返回0。
//测试样例：
//[1, 2, 3, 2, 2], 5
//返回：2

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getValue(vector<int> gifts, int n) {
	// write code here
	/*sort(gifts.begin(), gifts.end());
	int cnt = 1;
	for (int i = 1; i < n; i++) {
		if (gifts[i] == gifts[i - 1]) {
			cnt++;
			if (cnt > n / 2) {
				return gifts[i];
			}
		}
		else {
			cnt = 1;
		}
	}
	return 0;*/
	int cnt = 1;
	int tmp = gifts[0];
	for (int i = 0; i < n; i++) {
		if (tmp == gifts[i]) {
			cnt++;
		}
		else {
			cnt--;
			if (cnt == 0) {
				cnt = 1;
				tmp = gifts[i];
			}
		}
	}
	cnt = 0;
	for (int i = 0; i < n; i++) {
		if (gifts[i] == tmp) {
			cnt++;
			if (cnt > n / 2) {
				return tmp;
			}
		}
	}
	return 0;
}

int main(void) {

	int n;
	while (cin >> n) {
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		cout << getValue(v,n) << endl;
	}
	
	system("pause");
	return 0;
}