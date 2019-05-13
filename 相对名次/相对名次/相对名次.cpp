//���� N ���˶�Ա�ĳɼ����ҳ����ǵ�������β�����ǰ������Ӧ�Ľ��ơ�ǰ�����˶�Ա���ᱻ�ֱ����� �����ơ��������ơ� �͡� ͭ�ơ���"Gold Medal", "Silver Medal", "Bronze Medal"����
//
//(ע������Խ�ߵ�ѡ�֣�����Խ��ǰ��)
//
//ʾ�� 1:
//
//����: [5, 4, 3, 2, 1]
//	��� : ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
//	���� : ǰ�����˶�Ա�ĳɼ�Ϊǰ���ߵģ���˽���ֱ����� �����ơ��������ơ��͡�ͭ�ơ�("Gold Medal", "Silver Medal" and "Bronze Medal").
//	���µ������˶�Ա������ֻ��Ҫͨ�����ǵĳɼ����㽫��������μ��ɡ�
//	��ʾ :
//
//	N ��һ�����������Ҳ��ᳬ�� 10000��
//		�����˶�Ա�ĳɼ�������ͬ��

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

//��ͨ˼·    ���������Σ�������������
//vector<string> findRelativeRanks(vector<int>& nums) {
//	vector<int> num = nums;
//	sort(num.begin(), num.end());
//	reverse(num.begin(), num.end());
//	vector<string> v;
//	for (int i = 0; i < nums.size(); i++) {
//		for (int j = 0; j < num.size(); j++) {
//			if (nums[i] == num[j]) {
//				if (j > 2) {
//					v.push_back(to_string(j + 1));
//				}
//				if (j == 0) {
//					v.push_back("Gold Medal");
//				}
//				if (j == 1) {
//					v.push_back("Silver Medal");
//				}
//				if (j == 2) {
//
//					v.push_back("Bronze Medal");
//				}
//			}
//		}
//	}
//	return v;
//}



vector<string> findRelativeRanks(vector<int>& nums) {
	vector<int> tmp = nums;
	sort(tmp.begin(), tmp.end(), greater<int>()); //�Ӵ�С����
	unordered_map<int, int> intMap;
	for (int i = 0; i < tmp.size(); i++) {
		intMap[tmp[i]] = i + 1;
	}

	vector<string> ans(nums.size());
	for (int i = 0; i < nums.size(); i++) {
		int tmp = intMap[nums[i]];
		if (tmp == 1)
			ans[i] = "Gold Medal";
		else if (tmp == 2)
			ans[i] = "Silver Medal";
		else if (tmp == 3)
			ans[i] = "Bronze Medal";
		else ans[i] = to_string(tmp);
	}

	return ans;
}

int main(void) {

	cout << "����������" << endl;
	int n;
	cin >> n;

	vector<int> v;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	vector<string> s = findRelativeRanks(v);
	for (int i = 0; i < s.size(); i++) {
		cout << s[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}