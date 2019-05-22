//给定一个非空整数数组，找到使所有数组元素相等所需的最小移动数，其中每次移动可将选定的一个元素加1或减1。
//您可以假设数组的长度最多为10000。
//例如 :
//输入:
//[1, 2, 3]
//输出 :
//	2
//	说明：
//	只有两个动作是必要的（记得每一步仅可使其中一个元素加1或减1）：
//	[1, 2, 3] = > [2, 2, 3] = > [2, 2, 2]


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//思路 ： 这道题不能用平均值，要用中位数解决问题，中位数
//        移到中位数必定是最少次数的，数组元素个数为奇偶数没有影响
int minMoves2(vector<int>& nums) {
	int len = nums.size();
	int mid = len / 2;
	sort(nums.begin(), nums.end());
	int ret = 0;
	for (int i = 0; i < len; i++) {
		ret += abs(nums[i] - nums[mid]);
	}
	return ret;
}

int main(void) {

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cout << minMoves2(v) << endl;
	system("pause");
	return 0;
}