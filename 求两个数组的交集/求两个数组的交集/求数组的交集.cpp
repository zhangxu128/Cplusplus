#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
//�����������飬��дһ���������������ǵĽ�����
//ʾ�� 1:
//  ����: nums1 = [1, 2, 2, 1], nums2 = [2, 2]
//	��� : [2]
//	ʾ�� 2 :
//	���� : nums1 = [4, 9, 5], nums2 = [9, 4, 9, 8, 4]
//	��� : [9, 4]

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		map<int, int>record;
		for (int i = 0; i < nums1.size(); i++)
		{
			record[nums1[i]]++;

		}
		vector<int> res;
		for (int i = 0; i < nums2.size(); i++) {
			if (record[nums2[i]] > 0)
				res.push_back(nums2[i]);
			record.erase(nums2[i]);
		}
		return res;
	}
};



void print(vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

int main()
{
	int nums1[] = { 1,2,2,1};
	int nums2[] = {2,2,4};
	int size1 = sizeof(nums1) / sizeof(int);
	int size2 = sizeof(nums2) / sizeof(int);
	vector<int> v1(nums1, nums1 + size1);
	vector<int> v2(nums1, nums1 + size2);
	Solution s;
	vector<int>v = s.intersection(v1, v2);
	print(v);
	system("pause");
	return 0;
}