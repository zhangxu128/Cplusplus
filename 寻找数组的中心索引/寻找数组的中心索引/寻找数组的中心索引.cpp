#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

//����һ���������͵����� nums�����дһ���ܹ��������顰�����������ķ�����
//���������������������������ģ����������������������Ԫ����ӵĺ͵����Ҳ�����Ԫ����ӵĺ͡�
//������鲻����������������ô����Ӧ�÷��� - 1����������ж��������������ô����Ӧ�÷��������ߵ���һ����
//ʾ�� 1:
//����:
//nums = [1, 7, 3, 6, 5, 6]
//��� : 3
//	���� :
//	����3(nums[3] = 6) �������֮��(1 + 7 + 3 = 11)�����Ҳ���֮��(5 + 6 = 11)��ȡ�
//	ͬʱ, 3 Ҳ�ǵ�һ������Ҫ�������������



//˼·����Ԫ���ۺ�sum , sum - �����������ҵ�ֵ���Ǹ������µ�ֵ���ⷽ�̼���
class Solution {
public:
	int pivotIndex(vector<int>& nums) {
		int scur = 0, sum = accumulate(nums.begin(), nums.end(), 0);
		for (int i = 0; i < nums.size(); ++i) {
			if (sum - 2 * scur == nums[i]) return i;
			scur += nums[i];
		}
		return -1;

	}
};

int main(void) {
	int nums[] = { 1,7,3,6,5,6 };
	vector<int>v(nums, nums + 6);
	Solution s;
	cout << s.pivotIndex(v) << endl;
	system("pause");
	return 0;
}