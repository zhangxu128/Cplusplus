//给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。
//返回这三个数的和。假定每组输入只存在唯一答案。
//例如，给定数组 nums = [-1，2，1， - 4], 和 target = 1.
//与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).


#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

//利用双指针 求绝对差值

int threeSumClosest(vector<int>& nums, int target) {
	if (nums.size() < 3)
		return {};

	sort(nums.begin(), nums.end());
	int res = accumulate(nums.begin(), nums.begin() + 3, 0);
	int mn = abs(target - res);
	for (int i = 0; i < nums.size(); i++) {
		int fix = target - nums[i];
		int l = i + 1, r = nums.size() - 1;
		//对撞指针
		while (l < r) {
			if (nums[l] + nums[r] == fix)
				return target;
			else {
				if (abs(nums[l] + nums[r] - fix) < mn) {
					mn = abs(nums[l] + nums[r] - fix);
					res = nums[l] + nums[r] + nums[i];
				}
				if (nums[l] + nums[r] > fix)
					r--;
				else if (nums[l] + nums[r] < fix)
					l++;
			}
		}
	}
	return res;
}

int main(void) {

	cout << "请输入数组元素个数" << endl;
	int n;
	cin >> n;
	cout << "请输入目标数" << endl;
	int target;
	cin >> target;
	int num;
	vector<int> v;
	cout << "输入数组元素" << endl;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	cout << threeSumClosest(v, target) << endl;
	system("pause");
	return 0;
}