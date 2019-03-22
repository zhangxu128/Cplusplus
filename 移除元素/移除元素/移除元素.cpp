#include<iostream>
#include<vector>
using namespace std;

//给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。
//不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
//元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
//
//示例 1:
//给定 nums = [3, 2, 2, 3], val = 3,
//函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。
//你不需要考虑数组中超出新长度后面的元素。

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int k = 0;
		for (unsigned int i = 0; i < nums.size(); i++)
			if (nums[i] != val)
				nums[k++] = nums[i];

		return k;
	}
};

int main()
{
	int nums[4] = { 3,2,2,3 };
	vector<int> num;
	for (int i = 0; i < 4; i++)
	{
		num.push_back(nums[i]);
	}
	Solution s;
	int value = 3;
	cout << s.removeElement(num, value) << endl;
	system("pause");
	return 0;
}