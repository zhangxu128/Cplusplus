#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//����һ������Ϊ n �ķǿ��������飬�ҵ�����������Ԫ����ȵ���С�ƶ�������ÿ���ƶ�����ʹ n - 1 ��Ԫ������ 1��
//ʾ�� :
//  ����:
//  [1, 2, 3]
//  ��� :
//	3
//	���� :
//	ֻ��Ҫ3���ƶ���ע��ÿ���ƶ�����������Ԫ�ص�ֵ����
//	[1, 2, 3] = > [2, 3, 3] = > [3, 4, 3] = > [4, 4, 4]

int minMoves(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i];
	}
	cout << endl;
	int count = 0;
	while (nums[0] != nums.back())
	{
		for (int i = 0; i < nums.size() - 1; i++)
		{
			nums[i]++;
		}
		count++;
		sort(nums.begin(), nums.end());
	}
	return count;
}

int main(void)
{
	vector<int> v;
	v.push_back(1);
	v.push_back(4);
	v.push_back(7);
	v.push_back(9);
	//cout << v.back(1);
	cout << minMoves(v) << endl;
	system("pause");
	return 0;
}