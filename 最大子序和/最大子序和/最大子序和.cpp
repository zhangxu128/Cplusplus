#include <iostream>
#include <vector>

using namespace std;

//����һ���������� nums ���ҵ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�
//ʾ�� :
//    ����: [-2, 1, -3, 4, -1, 2, 1, -5, 4],
//	��� : 6
//	���� : ����������[4, -1, 2, 1] �ĺ����Ϊ 6��

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int len = nums.size();
		int * p = new int[len];
		int max = nums[0];
		for (int i = 0; i < len; i++) {
			if (i == 0) {
				p[i] = nums[i];
				continue;
			}
			int sum = nums[i] + p[i - 1];
			if (sum > nums[i]) {
				p[i] = sum;

			}
			else {
				p[i] = nums[i];
			}
			if (max < p[i]) {
				max = p[i];
			}
		}
		return max;
	}
};

int main(void) {

	int n;
	cin >> n;  //����n����

	int num;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	Solution s;
	cout<<"�������ͣ�"<<s.maxSubArray(v)<<endl;
	system("pause");
	return 0;
}
  