#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

//给定一个整数数组，判断是否存在重复元素。
//如果任何值在数组中出现至少两次，函数返回 true。
//如果数组中每个元素都不相同，则返回 false。
//输入: [1, 2, 3, 1]
//输出 : true
bool containsDuplicate(vector<int>& nums) {
	//进行排序后只需比较相邻两个数即可
	if (nums.size() < 2)
	{
		return false;
	}
	sort(nums.begin(), nums.end());
	//遍历排序之后的数组元素
	for (unsigned int i = 0; i < nums.size(); i++)
	{
		cout << nums.at(i) << " ";
	}
	cout << endl;
	int temp = nums[0];
	for (unsigned int i = 1; i < nums.size(); i++)
	{
		if (nums[i] == temp)
		{
			return true;
		}
		else
		{
			temp = nums[i];
		}
	}
	return false;
}

int main()
{
	int num[] = { 1,2,3,4,5,6,2};
	int size = sizeof(num) / sizeof(int);
	vector<int> vnum;
	for (int i = 0; i < size; i++)
	{
		vnum.push_back(num[i]);
	}
	cout << containsDuplicate(vnum) << endl;
	system("pause");
	return 0;
}