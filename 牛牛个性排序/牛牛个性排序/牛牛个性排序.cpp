//��Ŀ����
//ţţ��һ������Ϊn����������, ţţ���������н�������Ϊһ�����ϸ��������С�ţţ�Ƚ�����, �����ƶ������ٵ������������, �����������һ����������Ҫ�ƶ����ٸ������е�Ԫ�ء�(��һ��Ԫ�ز�����ԭ�����ڵ�λ��, ���Ԫ�ؾ��Ǳ��ƶ��˵�)
//��������:
//�����������, ��һ��һ������n(1 �� n �� 50), �����еĳ���
//�ڶ���n������x[i](1 �� x[i] �� 100), �������е�ÿ����
//������� :
//���һ������, ��������Ҫ�ƶ���Ԫ�ظ���
//ʾ��1
//����
//3
//3 2 1
//���
//2


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int num, x;
	cin >> num;
	vector<int> nums, temp;
	while (num--)
	{
		cin >> x;
		nums.push_back(x);
		temp.push_back(x);
	}
	sort(nums.begin(), nums.end());
	int cnt = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] != temp[i])
			cnt++;
	}
	cout << cnt << endl;
	system("pause");
	return 0;
}