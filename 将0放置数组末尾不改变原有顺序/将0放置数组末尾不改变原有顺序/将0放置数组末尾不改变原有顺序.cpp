#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��
//ʾ�� :
//  ����: [0, 1, 0, 3, 12]
//	��� : [1, 3, 12, 0, 0]
//	˵�� :
//	������ԭ�����ϲ��������ܿ�����������顣
//	�������ٲ���������
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int i = 0, j = 0;
		for (i = 0; i < nums.size(); i++)
		{
			if (nums[i] != 0)
			{
				nums[j++] = nums[i];
			}
		}
		while (j < nums.size())
		{
			nums[j++] = 0;
		}

	}
};

int main() {
	vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(0);
	v.push_back(3);
	v.push_back(12);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	Solution s;
	s.moveZeroes(v);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}