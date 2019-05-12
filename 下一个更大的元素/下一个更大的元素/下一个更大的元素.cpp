//给定两个没有重复元素的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。
//找到 nums1 中每个元素在 nums2 中的下一个比其大的值。
//nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。
//如果不存在，对应位置输出 - 1。
//    示例 1:
//	输入: nums1 = [4, 1, 2], nums2 = [1, 3, 4, 2].
//	输出 : [-1, 3, -1]
//	解释 :
//	对于num1中的数字4，你无法在第二个数组中找到下一个更大的数字，因此输出 - 1。
//	对于num1中的数字1，第二个数组中数字1右边的下一个较大数字是 3。
//	对于num1中的数字2，第二个数组中没有下一个更大的数字，因此输出 - 1。
//	示例 2 :
//	输入 : nums1 = [2, 4], nums2 = [1, 2, 3, 4].
//	输出 : [3, -1]
//	解释 :
//	对于num1中的数字2，第二个数组中的下一个较大数字是3。
//	对于num1中的数字4，第二个数组中没有下一个更大的数字，因此输出 - 1。
//	注意 :
//	nums1和nums2中所有元素是唯一的。
//		nums1和nums2 的数组大小都不超过1000。


#include <iostream>
#include <vector>


using namespace std;

//思路：挨个遍历
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
	vector<int> v;
	// 2 4      4    1    2
	//1 2 3 4   1    3    4    2
	for (int i = 0; i < nums1.size(); i++) {
		int j;
		for (j = 0; j < nums2.size();j++) {
			if (nums1[i] == nums2[j]) {
				while (j < nums2.size()) {
					if (nums2[j] > nums1[i]) {
						v.push_back(nums2[j]);
						break;
					}
					j++;
				}
				if (j == nums2.size()) {
					v.push_back(-1);
					break;
				}
			}
		}
	}
	return v;
}

int main(void){

	cout << "请输入数组1元素个数" << endl;
	int n;
	cin >> n;
	vector<int> v1, v2;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v1.push_back(num);
	}
	cout << "请输入数组2元素个数" << endl;
	int n1;
	cin >> n1;
	for (int i = 0; i < n1; i++) {
		cin >> num;
		v2.push_back(num);
	}
	vector<int> ret = nextGreaterElement(v1, v2);
	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0; 
}

