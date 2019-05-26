//����һ�����������һ������ k������Ҫ�ҵ��������к�Ϊ k ��������������ĸ�����
//
//ʾ�� 1 :
//
//����:nums = [1, 1, 1], k = 2
//	��� : 2, [1, 1] ��[1, 1] Ϊ���ֲ�ͬ�������
//	˵�� :
//
//   ����ĳ���Ϊ[1, 20, 000]��
//	   ������Ԫ�صķ�Χ��[-1000, 1000] �������� k �ķ�Χ��[-1e7, 1e7]��

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
	int res = 0;
	unordered_map<int, int> record;
	record[0] = 1;
	for (int i = 0, psum = 0; i != nums.size(); ++i) {
		psum += nums[i];
		if (record.count(psum - k) > 0)
			res += record[psum - k];
		++record[psum];
	}
	return res;
}

int main(void){

	int n;
	cout << "��������Ԫ�ظ���" << endl;
	cin >> n;
	vector<int> v(n);
	cout << "��������Ԫ��" << endl;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cout << "����Ŀ����" << endl;
	int k;
	cin >> k;
	cout << subarraySum(v, k) << endl;
	system("pause");
	return 0;
}