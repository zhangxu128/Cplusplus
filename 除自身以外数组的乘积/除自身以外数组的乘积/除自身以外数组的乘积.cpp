//给定长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 
//等于 nums 中除 nums[i] 之外其余各元素的乘积。
//示例 :
//输入: [1, 2, 3, 4]
//	输出 : [24, 12, 8, 6]
//	说明 : 请不要使用除法，且在 O(n) 时间复杂度内完成此题。
//	进阶：
//	你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）


#include <iostream>
#include <vector>

using namespace std;


//分别左右遍历累积即可
vector<int> productExceptSelf(vector<int>& nums) {
	int left = 1;
	int right = 1;
	vector<int> output;
	output.resize(nums.size());
	int len = nums.size();
	for (int i = 0; i < len; i++) {
		output[i] = left;
		left *= nums[i];
	}
	for (int j = len - 1; j >= 0; j--) {
		output[j] *= right;
		right *= nums[j];
	}
	return output;
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
	vector<int> ret = productExceptSelf(v);
	for (int i : ret) {
		cout << i << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}