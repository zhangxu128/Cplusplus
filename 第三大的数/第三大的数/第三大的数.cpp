//����һ���ǿ����飬���ش������е������������������ڣ�
//�򷵻���������������Ҫ���㷨ʱ�临�Ӷȱ�����O(n)��
//ʾ�� 1:
//����: [3, 2, 1]
//	��� : 1
//	���� : ����������� 1.
//	ʾ�� 2 :
//	���� : [1, 2]
//	��� : 2
//	���� : �����ڣ�����������


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

	cout << "���������ݵĸ���n=";
	int n;
	cin >> n;
	int num;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	cout << "�����������" << thirdMax(v) << endl;
	system("pause");
	return 0;
}