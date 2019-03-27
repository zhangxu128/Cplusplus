#include<iostream>
#include<vector>
using namespace std;

//����һ�����������飬 ���������������1�ĸ�����
//
//ʾ�� 1:
//
//����: [1, 1, 0, 1, 1, 1]
//	��� : 3
//	���� : ��ͷ����λ��������λ��������1�������������1�ĸ����� 3.
//	ע�⣺
//
//	���������ֻ���� 0 ��1��
//	��������ĳ��������������Ҳ����� 10, 000��

int findMaxConsecutiveOnes(vector<int>& nums) 
{
	int count = 0;
	int max = 0;
	for (int i = 0; i < nums.size(); i++)  //  1 0 1 1 0 1
	{
		if (nums[i] == 0)
		{
			if (max <= count)
			{
				max = count;
				count = 0;
			}
			else
			{
				count = 0;
			}
			continue;
		}
		count++;
	}
	if (max < count)
	{
		return count;
	}
	return max;
}

int main()
{
	int arr[] = {0,1,1,1,1,0,1};
	int size = sizeof(arr) / sizeof(arr[0]);
	vector<int> v(arr,arr+size);
	cout << findMaxConsecutiveOnes(v) << endl;
	system("pause");
	return 0;
}