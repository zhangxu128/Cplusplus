//����һ��Ǹ������������������ǵ�˳��ʹ֮���һ������������
//ʾ�� 1:
//����: [10, 2]
//	��� : 210
//	ʾ�� 2 
//	���� : [3, 30, 34, 5, 9]
//	��� : 9534330
//	˵�� : ���������ܷǳ�����������Ҫ����һ���ַ���������������


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//�����Ҫ�������ǵ��Զ����������⣬���ݹ��������ϼ���
class Solution {
public:
	//�Զ�������
	static bool sortmax(const string& s1, const string& s2) {
		return s1 + s2 > s2 + s1;
	}
	string largestNumber(vector<int>& nums) {
		string s = "";
		vector<string> vs;
		for (int i = 0; i < nums.size(); i++) {
			vs.push_back(to_string(nums[i]));
		}
		sort(vs.begin(), vs.end(), sortmax);
		if (vs[0] == "0" && vs[vs.size() - 1] == "0") {
			return "0";
		}
		for (int i = 0; i < vs.size(); i++) {
			s += vs[i];
		}
		return s;
	}
};
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
	Solution s;
	cout << s.largestNumber(v) << endl;
	system("pause");
	return 0;
}