#include <iostream>
#include <string >
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
	if (strs.empty()) {
		return "";
	}
	// ��ֹ����������һ���ַ��������β������������ͬ���ַ�        
	int i_char = 0;
	while (true) {
		// ����Ƿ�Խ�磬�Լ���ǰλ�ַ��Ƿ���ͬ
		for (int i_strs = 0; i_strs < strs.size(); i_strs++) {
			if (
				i_char == strs[i_strs].size() // �Ƿ�Խ��
				||
				strs[i_strs][i_char] != strs[0][i_char] // ��ǰλ�ַ��Ƿ���ͬ
				) 
			{
				return strs[i_strs].substr(0, i_char);
			}
		}
		i_char++;
	}
}


int main(void) {
	
	string s;
	vector<string> v;
	
	int n;//����n���ַ���
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}

	string ret = longestCommonPrefix(v);

	cout << ret << endl;
	system("pause");
	return 0;
}