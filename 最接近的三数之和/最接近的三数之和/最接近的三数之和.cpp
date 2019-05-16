//����һ������ n ������������ nums �� һ��Ŀ��ֵ target���ҳ� nums �е�����������ʹ�����ǵĺ��� target ��ӽ���
//�������������ĺ͡��ٶ�ÿ������ֻ����Ψһ�𰸡�
//���磬�������� nums = [-1��2��1�� - 4], �� target = 1.
//�� target ��ӽ����������ĺ�Ϊ 2. (-1 + 2 + 1 = 2).


#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

//����˫ָ�� ����Բ�ֵ

int threeSumClosest(vector<int>& nums, int target) {
	if (nums.size() < 3)
		return {};

	sort(nums.begin(), nums.end());
	int res = accumulate(nums.begin(), nums.begin() + 3, 0);
	int mn = abs(target - res);
	for (int i = 0; i < nums.size(); i++) {
		int fix = target - nums[i];
		int l = i + 1, r = nums.size() - 1;
		//��ײָ��
		while (l < r) {
			if (nums[l] + nums[r] == fix)
				return target;
			else {
				if (abs(nums[l] + nums[r] - fix) < mn) {
					mn = abs(nums[l] + nums[r] - fix);
					res = nums[l] + nums[r] + nums[i];
				}
				if (nums[l] + nums[r] > fix)
					r--;
				else if (nums[l] + nums[r] < fix)
					l++;
			}
		}
	}
	return res;
}

int main(void) {

	cout << "����������Ԫ�ظ���" << endl;
	int n;
	cin >> n;
	cout << "������Ŀ����" << endl;
	int target;
	cin >> target;
	int num;
	vector<int> v;
	cout << "��������Ԫ��" << endl;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	cout << threeSumClosest(v, target) << endl;
	system("pause");
	return 0;
}