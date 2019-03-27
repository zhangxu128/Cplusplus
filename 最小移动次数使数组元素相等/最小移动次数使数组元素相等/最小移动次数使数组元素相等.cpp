#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//给定一个长度为 n 的非空整数数组，找到让数组所有元素相等的最小移动次数。每次移动可以使 n - 1 个元素增加 1。
//示例 :
//  输入:
//  [1, 2, 3]
//  输出 :
//	3
//	解释 :
//	只需要3次移动（注意每次移动会增加两个元素的值）：
//	[1, 2, 3] = > [2, 3, 3] = > [3, 4, 3] = > [4, 4, 4]

int minMoves(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i];
	}
	cout << endl;
	int count = 0;
	while (nums[0] != nums.back())
	{
		for (int i = 0; i < nums.size() - 1; i++)
		{
			nums[i]++;
		}
		count++;
		sort(nums.begin(), nums.end());
	}
	return count;
}

int main(void)
{
	vector<int> v;
	v.push_back(1);
	v.push_back(4);
	v.push_back(7);
	v.push_back(9);
	//cout << v.back(1);
	cout << minMoves(v) << endl;
	system("pause");
	return 0;
}