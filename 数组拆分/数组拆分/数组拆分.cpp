#include<iostream>
#include<vector>
#include<algorithm>
//��������Ϊ 2n ������, ��������ǽ���Щ���ֳ� n ��, ����(a1, b1), (a2, b2), ..., (an, bn) 
//ʹ�ô�1 �� n �� min(ai, bi) �ܺ����
//  ʾ�� 1:
//  ����: [1, 4, 3, 2]
//	��� : 4
//	���� : n ���� 2, ����ܺ�Ϊ 4 = min(1, 2) + min(3, 4).
using namespace std;

int min(int a, int b) {
	return a <= b ? a : b;
}

int arrayPairSum(vector<int>& nums) {
	int sum = 0;
	sort(nums.begin(), nums.end());
	if (nums.size() % 2 != 0) {
		for (int i = 0; i < nums.size() - 1; i+=2) {
			sum += min(nums[i], nums[i + 1]);
		}
		sum += nums[nums.size() - 1];
	}
	else {
		for (int i = 0; i < nums.size() - 1; i += 2) {
			sum += min(nums[i], nums[i + 1]);
		}
	}
	return sum;
}

int main() {

	vector<int> v;
	v.push_back(1);
	v.push_back(4);
	v.push_back(3);
	v.push_back(2);
	cout << arrayPairSum(v) << endl;
	system("pause");
	return 0;
}