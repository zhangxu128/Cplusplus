//给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。
//
//示例 1 :
//
//输入:nums = [1, 1, 1], k = 2
//	输出 : 2, [1, 1] 与[1, 1] 为两种不同的情况。
//	说明 :
//
//   数组的长度为[1, 20, 000]。
//	   数组中元素的范围是[-1000, 1000] ，且整数 k 的范围是[-1e7, 1e7]。

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
	int res = 0;
	unordered_map<int, int> record;
	record[0] = 1;
	for (int i = 0, psum = 0; i != nums.size(); ++i) {
		psum += nums[i];
		if (record.count(psum - k) > 0)
			res += record[psum - k];
		++record[psum];
	}
	return res;
}

int main(void){

	int n;
	cout << "输入数组元素个数" << endl;
	cin >> n;
	vector<int> v(n);
	cout << "输入数组元素" << endl;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cout << "输入目标数" << endl;
	int k;
	cin >> k;
	cout << subarraySum(v, k) << endl;
	system("pause");
	return 0;
}