#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
//示例 :
//  输入: [0, 1, 0, 3, 12]
//	输出 : [1, 3, 12, 0, 0]
//	说明 :
//	必须在原数组上操作，不能拷贝额外的数组。
//	尽量减少操作次数。
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int i = 0, j = 0;
		for (i = 0; i < nums.size(); i++)
		{
			if (nums[i] != 0)
			{
				nums[j++] = nums[i];
			}
		}
		while (j < nums.size())
		{
			nums[j++] = 0;
		}

	}
};

int main() {
	vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(0);
	v.push_back(3);
	v.push_back(12);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	Solution s;
	s.moveZeroes(v);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}