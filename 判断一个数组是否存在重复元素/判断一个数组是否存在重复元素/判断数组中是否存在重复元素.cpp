#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

//����һ���������飬�ж��Ƿ�����ظ�Ԫ�ء�
//����κ�ֵ�������г����������Σ��������� true��
//���������ÿ��Ԫ�ض�����ͬ���򷵻� false��
//����: [1, 2, 3, 1]
//��� : true
bool containsDuplicate(vector<int>& nums) {
	//���������ֻ��Ƚ���������������
	if (nums.size() < 2)
	{
		return false;
	}
	sort(nums.begin(), nums.end());
	//��������֮�������Ԫ��
	for (unsigned int i = 0; i < nums.size(); i++)
	{
		cout << nums.at(i) << " ";
	}
	cout << endl;
	int temp = nums[0];
	for (unsigned int i = 1; i < nums.size(); i++)
	{
		if (nums[i] == temp)
		{
			return true;
		}
		else
		{
			temp = nums[i];
		}
	}
	return false;
}

int main()
{
	int num[] = { 1,2,3,4,5,6,2};
	int size = sizeof(num) / sizeof(int);
	vector<int> vnum;
	for (int i = 0; i < size; i++)
	{
		vnum.push_back(num[i]);
	}
	cout << containsDuplicate(vnum) << endl;
	system("pause");
	return 0;
}