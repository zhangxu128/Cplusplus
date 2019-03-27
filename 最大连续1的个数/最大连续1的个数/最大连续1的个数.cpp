#include<iostream>
#include<vector>
using namespace std;

//给定一个二进制数组， 计算其中最大连续1的个数。
//
//示例 1:
//
//输入: [1, 1, 0, 1, 1, 1]
//	输出 : 3
//	解释 : 开头的两位和最后的三位都是连续1，所以最大连续1的个数是 3.
//	注意：
//
//	输入的数组只包含 0 和1。
//	输入数组的长度是正整数，且不超过 10, 000。

int findMaxConsecutiveOnes(vector<int>& nums) 
{
	int count = 0;
	int max = 0;
	for (int i = 0; i < nums.size(); i++)  //  1 0 1 1 0 1
	{
		if (nums[i] == 0)
		{
			if (max <= count)
			{
				max = count;
				count = 0;
			}
			else
			{
				count = 0;
			}
			continue;
		}
		count++;
	}
	if (max < count)
	{
		return count;
	}
	return max;
}

int main()
{
	int arr[] = {0,1,1,1,1,0,1};
	int size = sizeof(arr) / sizeof(arr[0]);
	vector<int> v(arr,arr+size);
	cout << findMaxConsecutiveOnes(v) << endl;
	system("pause");
	return 0;
}