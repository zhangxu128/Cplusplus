#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//��Ŀ����
//�����Ͷ����Ǻ����ѡ�������ϲ�����ġ�������ָ��ǰ������ʹӺ���ǰ����һ���Ĵ��
//����׼��������һ����ϲ, ��ȡ��һ���ַ���s, Ȼ���ں��渽��0�����߸������ĸ�γɻ���,
//����ϣ���������Խ��Խ�á�����������������ܹ��õ�����̵Ļ��ĳ��ȡ�

// ����  abab
// ���  5

bool isloop(string s) {
	string str = s;
	reverse(s.begin(), s.end());
	if (str == s) {
		return true;
	}
	return false;
}

int main(void) {
	string s;
	int count = 0;
	
	while (cin >> s) {
		if (isloop(s)) {
			cout << s.size() << endl;
			continue;
		}
		for (int i = 1; i < s.size(); i++) {
			string str(s.begin() + i, s.end());
			if (isloop(str)) {
				count = i;
				break;
			}
		}
		cout << count + s.size() << endl;
	}
	system("pause");
	return 0;
}