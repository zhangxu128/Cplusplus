#include <iostream>
#include <vector>
using namespace std;


//����һ�������������е��������� nums����һ��Ŀ��ֵ target���ҳ�����Ŀ��ֵ�������еĿ�ʼλ�úͽ���λ�á�
//����㷨ʱ�临�Ӷȱ����� O(log n) ����
//��������в�����Ŀ��ֵ������[-1, -1]��
//    ʾ�� 1:
//    ����: nums = [5, 7, 7, 8, 8, 10], target = 8
//	��� : [3, 4]
//	ʾ�� 2 
//	���� : nums = [5, 7, 7, 8, 8, 10], target = 6
//	��� : [-1, -1]

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