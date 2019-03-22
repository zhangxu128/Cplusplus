#include<iostream>
#include<vector>
using namespace std;

//����һ������ nums ��һ��ֵ val������Ҫԭ���Ƴ�������ֵ���� val ��Ԫ�أ������Ƴ���������³��ȡ�
//��Ҫʹ�ö��������ռ䣬�������ԭ���޸��������鲢��ʹ�� O(1) ����ռ����������ɡ�
//Ԫ�ص�˳����Ըı䡣�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
//
//ʾ�� 1:
//���� nums = [3, 2, 2, 3], val = 3,
//����Ӧ�÷����µĳ��� 2, ���� nums �е�ǰ����Ԫ�ؾ�Ϊ 2��
//�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int k = 0;
		for (unsigned int i = 0; i < nums.size(); i++)
			if (nums[i] != val)
				nums[k++] = nums[i];

		return k;
	}
};

int main()
{
	int nums[4] = { 3,2,2,3 };
	vector<int> num;
	for (int i = 0; i < 4; i++)
	{
		num.push_back(nums[i]);
	}
	Solution s;
	int value = 3;
	cout << s.removeElement(num, value) << endl;
	system("pause");
	return 0;
}