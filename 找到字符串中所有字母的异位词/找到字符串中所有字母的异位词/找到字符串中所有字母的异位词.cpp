//����һ���ַ��� s ��һ���ǿ��ַ��� p���ҵ� s �������� p ����ĸ��λ�ʵ��Ӵ���������Щ�Ӵ�����ʼ������
//�ַ���ֻ����СдӢ����ĸ�������ַ��� s �� p �ĳ��ȶ������� 20100��
//˵����
//��ĸ��λ��ָ��ĸ��ͬ�������в�ͬ���ַ�����
//�����Ǵ������˳��
//ʾ�� 1:
//����:
//s: "cbaebabacd" p : "abc"
//
//	��� :
//	[0, 6]


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

vector<int> findAnagrams(string s, string p) {
	if (s.size() < p.size())
		return {};
	int l = 0, r = -1;
	vector<int> freq_s(26, 0), freq_p(26, 0), res;
	// ��ʼ������ֵ
	for (int i = 0; i < p.size(); i++) {
		freq_p[p[i] - 'a']++;
		freq_s[s[++r] - 'a']++;
	}
	if (freq_s == freq_p)
		res.push_back(l);
	// �̶����ȵĻ�������
	while (r < s.size() - 1) {
		freq_s[s[++r] - 'a']++;
		freq_s[s[l++] - 'a']--;
		if (freq_s == freq_p)
			res.push_back(l);
	}
	return res;
}
int main(void) {
	string s;
	cout << "�������ַ���1" << endl;
	cin >> s;
	string p;
	cout << "�������ַ���2" << endl;
	cin >> p;
	cout << "��λ�ʳ��ֵ�λ������" << endl;
	vector<int> v = findAnagrams(s, p);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}