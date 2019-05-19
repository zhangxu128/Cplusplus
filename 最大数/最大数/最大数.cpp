//给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。
//示例 1:
//输入: [10, 2]
//	输出 : 210
//	示例 2 
//	输入 : [3, 30, 34, 5, 9]
//	输出 : 9534330
//	说明 : 输出结果可能非常大，所以你需要返回一个字符串而不是整数。


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//此题就要用上我们的自定义排序问题，根据规则进行组合即可
class Solution {
public:
	//自定义排序
	static bool sortmax(const string& s1, const string& s2) {
		return s1 + s2 > s2 + s1;
	}
	string largestNumber(vector<int>& nums) {
		string s = "";
		vector<string> vs;
		for (int i = 0; i < nums.size(); i++) {
			vs.push_back(to_string(nums[i]));
		}
		sort(vs.begin(), vs.end(), sortmax);
		if (vs[0] == "0" && vs[vs.size() - 1] == "0") {
			return "0";
		}
		for (int i = 0; i < vs.size(); i++) {
			s += vs[i];
		}
		return s;
	}
};
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
	Solution s;
	cout << s.largestNumber(v) << endl;
	system("pause");
	return 0;
}