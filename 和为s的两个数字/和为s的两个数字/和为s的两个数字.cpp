#include<iostream>
#include<vector>
using namespace std;

//输入一个递增排序的数组和一个数字S，在数组中查找两个数，
//使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
//输出描述 :
//对应每个测试案例，输出两个数，小的先输出。

//思路：查找另一个数是否在数组里，因为已经有序，所以先找到的数肯定是乘积比较小的

class Solution {
public:
	bool binary_search(vector<int> array, int k) {
		int left = 0;
		int right = array.size() - 1;
		while (left <= right) {
			int mid = left + right;
			if (array[mid] == k) {
				return true;
			}
			else if (array[mid] > k) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		return false;
	}
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		vector<int> v;
		for (int i = 0; i < array.size(); i++) {
			if (binary_search(array, sum - array[i])) {
				v.push_back(array[i]);
				v.push_back(sum - array[i]);
				break;
			}
		}
		return v;
	}
};
int main(void) {
	
	int num[] = { 1,2,5,6,7,8,9 };
	vector<int> v(num, num + 7);
	int k = 0;
	cin >> k;
	Solution s;
	vector<int> ret = s.FindNumbersWithSum(v,k);
	cout << ret[0] << " " << ret[1] << endl;
	system("pause");
	return 0;
}