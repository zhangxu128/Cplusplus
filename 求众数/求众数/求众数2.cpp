//����һ����СΪ n �����飬�ҳ��������г��ֳ��� �� n / 3 �� �ε�Ԫ�ء�
//˵�� : Ҫ���㷨��ʱ�临�Ӷ�Ϊ O(n)���ռ临�Ӷ�Ϊ O(1)��
//	ʾ�� 1 :
//	���� : [3, 2, 3]
//	��� : [3]
//	ʾ�� 2 :
//	���� : [1, 1, 1, 3, 3, 2, 2, 2]
//	��� : [1, 2]

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

//�����,��¼���ֵĴ���,�ж��Ƿ���������
vector<int> majorityElement(vector<int>& nums) {
	vector<int> res;
	int n = nums.size();
	if (n == 0) return {};
	map<int, int> m;
	sort(nums.begin(), nums.end());
	int count = 0, cur = nums[0];
	for (int i = 0; i < n; i++) {
		if (cur == nums[i]) count++;
		else {
			count = 1;
			cur = nums[i];
		}
		m[cur] = count;
	}
	map<int, int>::iterator it = m.begin();
	for (it; it != m.end(); it++) {
		if (it->second > n / 3) res.push_back(it->first);
	}
	return res;

}

int main(void) {

	cout << "����������Ԫ��" << endl;
	int n;
	cin >> n;
	int num;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	vector<int> ret = majorityElement(v);
	for (int i : ret) {
		cout << i << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}