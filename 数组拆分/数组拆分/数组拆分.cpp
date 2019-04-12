#include<iostream>
#include<vector>
#include<algorithm>
//给定长度为 2n 的数组, 你的任务是将这些数分成 n 对, 例如(a1, b1), (a2, b2), ..., (an, bn) 
//使得从1 到 n 的 min(ai, bi) 总和最大。
//  示例 1:
//  输入: [1, 4, 3, 2]
//	输出 : 4
//	解释 : n 等于 2, 最大总和为 4 = min(1, 2) + min(3, 4).
using namespace std;

int min(int a, int b) {
	return a <= b ? a : b;
}

int arrayPairSum(vector<int>& nums) {
	int sum = 0;
	sort(nums.begin(), nums.end());
	if (nums.size() % 2 != 0) {
		for (int i = 0; i < nums.size() - 1; i+=2) {
			sum += min(nums[i], nums[i + 1]);
		}
		sum += nums[nums.size() - 1];
	}
	else {
		for (int i = 0; i < nums.size() - 1; i += 2) {
			sum += min(nums[i], nums[i + 1]);
		}
	}
	return sum;
}

int main() {

	vector<int> v;
	v.push_back(1);
	v.push_back(4);
	v.push_back(3);
	v.push_back(2);
	cout << arrayPairSum(v) << endl;
	system("pause");
	return 0;
}