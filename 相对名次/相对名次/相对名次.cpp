//给出 N 名运动员的成绩，找出他们的相对名次并授予前三名对应的奖牌。前三名运动员将会被分别授予 “金牌”，“银牌” 和“ 铜牌”（"Gold Medal", "Silver Medal", "Bronze Medal"）。
//
//(注：分数越高的选手，排名越靠前。)
//
//示例 1:
//
//输入: [5, 4, 3, 2, 1]
//	输出 : ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
//	解释 : 前三名运动员的成绩为前三高的，因此将会分别被授予 “金牌”，“银牌”和“铜牌”("Gold Medal", "Silver Medal" and "Bronze Medal").
//	余下的两名运动员，我们只需要通过他们的成绩计算将其相对名次即可。
//	提示 :
//
//	N 是一个正整数并且不会超过 10000。
//		所有运动员的成绩都不相同。

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

//普通思路    排序找名次，挨个入座即可
//vector<string> findRelativeRanks(vector<int>& nums) {
//	vector<int> num = nums;
//	sort(num.begin(), num.end());
//	reverse(num.begin(), num.end());
//	vector<string> v;
//	for (int i = 0; i < nums.size(); i++) {
//		for (int j = 0; j < num.size(); j++) {
//			if (nums[i] == num[j]) {
//				if (j > 2) {
//					v.push_back(to_string(j + 1));
//				}
//				if (j == 0) {
//					v.push_back("Gold Medal");
//				}
//				if (j == 1) {
//					v.push_back("Silver Medal");
//				}
//				if (j == 2) {
//
//					v.push_back("Bronze Medal");
//				}
//			}
//		}
//	}
//	return v;
//}



vector<string> findRelativeRanks(vector<int>& nums) {
	vector<int> tmp = nums;
	sort(tmp.begin(), tmp.end(), greater<int>()); //从大到小排序
	unordered_map<int, int> intMap;
	for (int i = 0; i < tmp.size(); i++) {
		intMap[tmp[i]] = i + 1;
	}

	vector<string> ans(nums.size());
	for (int i = 0; i < nums.size(); i++) {
		int tmp = intMap[nums[i]];
		if (tmp == 1)
			ans[i] = "Gold Medal";
		else if (tmp == 2)
			ans[i] = "Silver Medal";
		else if (tmp == 3)
			ans[i] = "Bronze Medal";
		else ans[i] = to_string(tmp);
	}

	return ans;
}

int main(void) {

	cout << "请输入人数" << endl;
	int n;
	cin >> n;

	vector<int> v;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	vector<string> s = findRelativeRanks(v);
	for (int i = 0; i < s.size(); i++) {
		cout << s[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}