//����һ���ǿ��������飬�ҵ�ʹ��������Ԫ������������С�ƶ���������ÿ���ƶ��ɽ�ѡ����һ��Ԫ�ؼ�1���1��
//�����Լ�������ĳ������Ϊ10000��
//���� :
//����:
//[1, 2, 3]
//��� :
//	2
//	˵����
//	ֻ�����������Ǳ�Ҫ�ģ��ǵ�ÿһ������ʹ����һ��Ԫ�ؼ�1���1����
//	[1, 2, 3] = > [2, 2, 3] = > [2, 2, 2]


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//˼· �� ����ⲻ����ƽ��ֵ��Ҫ����λ��������⣬��λ��
//        �Ƶ���λ���ض������ٴ����ģ�����Ԫ�ظ���Ϊ��ż��û��Ӱ��
int minMoves2(vector<int>& nums) {
	int len = nums.size();
	int mid = len / 2;
	sort(nums.begin(), nums.end());
	int ret = 0;
	for (int i = 0; i < len; i++) {
		ret += abs(nums[i] - nums[mid]);
	}
	return ret;
}

int main(void) {

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cout << minMoves2(v) << endl;
	system("pause");
	return 0;
}