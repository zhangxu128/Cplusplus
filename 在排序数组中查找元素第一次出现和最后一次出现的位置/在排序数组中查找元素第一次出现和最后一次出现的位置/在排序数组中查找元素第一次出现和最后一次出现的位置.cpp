#include <iostream>
#include <vector>
using namespace std;


//给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
//你的算法时间复杂度必须是 O(log n) 级别。
//如果数组中不存在目标值，返回[-1, -1]。
//    示例 1:
//    输入: nums = [5, 7, 7, 8, 8, 10], target = 8
//	输出 : [3, 4]
//	示例 2 
//	输入 : nums = [5, 7, 7, 8, 8, 10], target = 6
//	输出 : [-1, -1]

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> rtn;
		search(nums, 0, nums.size() - 1, target, rtn);
		return rtn;
	}
	void search(vector<int> nums, int low, int high, int target, vector<int> &rtn) {
		if (low > high) {
			rtn.push_back(-1);
			rtn.push_back(-1);
			return;
		}
		else {
			int mid = (low + high) / 2;
			if (nums[mid] == target) {
				int left = mid;
				int right = mid;
				while (left >= 0 && nums[left] == target) {
					left--;
				}
				while (right < nums.size() && nums[right] == target) {
					right++;
				}
				rtn.push_back(left + 1);
				rtn.push_back(right - 1);
				return;
			}
			else if (nums[mid] > target) {
				high = mid - 1;
				search(nums, low, high, target, rtn);
			}
			else {
				low = mid + 1;
				search(nums, low, high, target, rtn);
			}

		}
	}
};

int main(void) {

	int nums[] = { 1,2,3,3,3,3,5,6,8 };
	vector<int> v(nums,nums+9);
	Solution s;
	vector<int> ret = s.searchRange(v, 3);
	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}