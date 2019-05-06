#include <iostream>
#include <vector>

using namespace std;

//给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
//示例 :
//    输入: [-2, 1, -3, 4, -1, 2, 1, -5, 4],
//	输出 : 6
//	解释 : 连续子数组[4, -1, 2, 1] 的和最大，为 6。

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int len = nums.size();
		int * p = new int[len];
		int max = nums[0];
		for (int i = 0; i < len; i++) {
			if (i == 0) {
				p[i] = nums[i];
				continue;
			}
			int sum = nums[i] + p[i - 1];
			if (sum > nums[i]) {
				p[i] = sum;

			}
			else {
				p[i] = nums[i];
			}
			if (max < p[i]) {
				max = p[i];
			}
		}
		return max;
	}
};

int main(void) {

	int n;
	cin >> n;  //输入n个数

	int num;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	Solution s;
	cout<<"最大子序和："<<s.maxSubArray(v)<<endl;
	system("pause");
	return 0;
}
  