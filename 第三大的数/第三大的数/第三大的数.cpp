//给定一个非空数组，返回此数组中第三大的数。如果不存在，
//则返回数组中最大的数。要求算法时间复杂度必须是O(n)。
//示例 1:
//输入: [3, 2, 1]
//	输出 : 1
//	解释 : 第三大的数是 1.
//	示例 2 :
//	输入 : [1, 2]
//	输出 : 2
//	解释 : 不存在，返回最大的数


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int thirdMax(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	reverse(nums.begin(), nums.end());
	if (nums.size() < 3) {
		return nums[0];
	}
	int cnt = 0;
	int i;
	for (i = 0; i < nums.size() - 1; i++) {
		if (nums[i] > nums[i + 1]) {
			cnt++;
		}
		if (cnt == 2) {
			return nums[i + 1];
		}
	}
	return nums[0];
}

int main(void) {

	cout << "请输入数据的个数n=";
	int n;
	cin >> n;
	int num;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	cout << "第三大的数是" << thirdMax(v) << endl;
	system("pause");
	return 0;
}