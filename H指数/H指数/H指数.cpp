//����һλ�о������ı����ô��������飨�����ô����ǷǸ�����������дһ��������������о��ߵ� h ָ����
//
//h ָ���Ķ��� : ��h ���������ô�������high citations����һ��������Ա�� h ָ����ָ���������� 
//��N ƪ�����У������� h ƪ���ķֱ����������� h �Ρ�������� N - h ƪ����ÿƪ�����ô��������� h �Ρ�����
//ʾ�� :
//
//����: citations = [3, 0, 6, 1, 5]
//	��� : 3
//	���� : ���������ʾ�о����ܹ��� 5 ƪ���ģ�ÿƪ������Ӧ�ı������� 3, 0, 6, 1, 5 �Ρ�
//�����о����� 3 ƪ����ÿƪ���ٱ������� 3 �Σ�������ƪ����ÿƪ�����ò����� 3 �Σ��������� h ָ���� 3��


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int rec, i;
	int hIndex(vector<int>& citations) {
		sort(citations.begin(), citations.end(), greater<int>()); //̰�Ĳ���
		for (i = 0; i < citations.size(); i++) {
			if (citations[i] < i + 1) { //�Ӵ���С��
				rec = i; break;
			}
		}
		if (i == citations.size()) rec = citations.size();
		return rec;
	}
};

int main(void) {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	Solution s;
	cout << s.hIndex(v) << endl;
	system("pause");
	return 0;
}