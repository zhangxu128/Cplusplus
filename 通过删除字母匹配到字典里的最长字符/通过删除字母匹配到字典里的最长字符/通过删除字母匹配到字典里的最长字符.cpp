//����һ���ַ�����һ���ַ����ֵ䣬�ҵ��ֵ���������ַ��������ַ�������ͨ��ɾ�������ַ�����ĳЩ�ַ����õ�������𰸲�ֹһ�������س�������ֵ�˳����С���ַ���������𰸲����ڣ��򷵻ؿ��ַ�����
//
//ʾ�� 1:
//
//����:
//s = "abpcplea", d = ["ale", "apple", "monkey", "plea"]
//
//��� :
//	"apple"
//	ʾ�� 2 :
//
//	���� :
//	s = "abpcplea", d = ["a", "b", "c"]
//
//	��� :
//	"a"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


//����󰴸����ֵ��ַ��Ƚ�
string findLongestWord(string s, vector<string>& d) {
	sort(d.begin(), d.end(), [](string &a, string &b) {
		if (a.size() != b.size())
			return a.size() > b.size();
		else
			return a < b;
	});

	for (int i = 0; i < d.size(); i++) {
		int j = 0, k = 0;
		while (k < s.size()) {
			if (s[k] == d[i][j])
				k++, j++;
			else
				k++;
		}
		if (j == d[i].size())
			return d[i];
	}
	return "";
}

int main(void) {
	cout << "��������Ԫ�ظ���" << endl;
	int n;
	cin >> n;
	cout << "��������Ԫ���ַ���" << endl;
	vector<string> v(n);
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}
	cout << "�����ֵ��ַ���" << endl;
	string str;
	cin >> str;
	cout << "��ַ���Ϊ" << findLongestWord(str,v) << endl;
	system("pause");
	return 0;
}