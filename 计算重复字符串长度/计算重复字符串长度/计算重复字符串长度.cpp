#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


//��Ŀ����
//����ַ������ҳ������ظ�һ�ε����ַ�������󳤶�
//�������� :
//�ַ��������Ȳ�����1000
//������� :
//�ظ��Ӵ��ĳ��ȣ����������0
//ʾ��1
//����
//ababcdabcefsgg
//���
//3
//abcΪ�ظ�������Ӵ�������Ϊ3

size_t getCommLen(string str1, string str2) {
	size_t i;
	for (i = 0; i < str1.size() && i < str2.size(); i++) {
		if (str1[i] != str2[i])
			break;
	}
	return i;
}
int main()
{
	string str;
	cin >> str;
	vector<string> strs;
	for (size_t i = 0; i < str.size(); i++) {
		strs.push_back(str.substr(i));
	//	cout << str.substr(i) << " ";
	}
	//cout << endl;
	sort(strs.begin(), strs.end());
	//�������ͬ�ִ����ض�����
	size_t maxLen = 0;
	for (size_t i = 0; i < strs.size() - 1; i++) {
		size_t len = getCommLen(strs[i], strs[i + 1]);
		maxLen = max(maxLen, len);
	}
	cout << maxLen << endl;
	system("pause");
	return 0;
}