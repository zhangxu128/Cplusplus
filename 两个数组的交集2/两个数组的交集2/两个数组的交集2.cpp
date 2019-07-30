//�����������飬��дһ���������������ǵĽ�����
//
//ʾ�� 1:
//
//����: nums1 = [1, 2, 2, 1], nums2 = [2, 2]
//	��� : [2, 2]
//	ʾ�� 2 :
//
//	���� : nums1 = [4, 9, 5], nums2 = [9, 4, 9, 8, 4]
//	��� : [4, 9]
//	˵����
//
//	��������ÿ��Ԫ�س��ֵĴ�����Ӧ��Ԫ�������������г��ֵĴ���һ�¡�
//	���ǿ��Բ�������������˳��

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
	unordered_map<int, int> unmap;
	for (auto e : nums1) {
		unmap[e]++;
	}

	vector<int> ret;
	for (auto e : nums2) {
		if (unmap.count(e)) {
			ret.push_back(e);
			unmap[e]--;
			if (unmap[e] == 0) {
				unmap.erase(e);
			}
		}
	}
	return ret;
}

int main(void) {

	int n, m;
	cin >> n >> m;
	vector<int> v1(n);
	vector<int> v2(m);
	for (int i = 0; i < n; i++) {
		cin >> v1[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> v2[i];
	}

	vector<int> ret = intersect(v1, v2);
	for (auto e : ret) {
		cout << e << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}