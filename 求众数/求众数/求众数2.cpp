//给定一个大小为 n 的数组，找出其中所有出现超过 【 n / 3 】 次的元素。
//说明 : 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1)。
//	示例 1 :
//	输入 : [3, 2, 3]
//	输出 : [3]
//	示例 2 :
//	输入 : [1, 1, 1, 3, 3, 2, 2, 2]
//	输出 : [1, 2]

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

//排序后,记录出现的次数,判断是否满足条件
vector<int> majorityElement(vector<int>& nums) {
	vector<int> res;
	int n = nums.size();
	if (n == 0) return {};
	map<int, int> m;
	sort(nums.begin(), nums.end());
	int count = 0, cur = nums[0];
	for (int i = 0; i < n; i++) {
		if (cur == nums[i]) count++;
		else {
			count = 1;
			cur = nums[i];
		}
		m[cur] = count;
	}
	map<int, int>::iterator it = m.begin();
	for (it; it != m.end(); it++) {
		if (it->second > n / 3) res.push_back(it->first);
	}
	return res;

}

int main(void) {

	cout << "请输入数组元素" << endl;
	int n;
	cin >> n;
	int num;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	vector<int> ret = majorityElement(v);
	for (int i : ret) {
		cout << i << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}