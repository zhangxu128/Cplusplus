#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//���������ַ��� s �� t������ֻ����Сд��ĸ��
//�ַ��� t ���ַ��� s ������ţ�Ȼ�������λ�����һ����ĸ
//���ҳ��� t �б���ӵ���ĸ��
//ʾ�� :
//���룺
//s = "abcd"
//t = "abcde"
//�����
//e
//���ͣ�
//'e' ���Ǹ�����ӵ���ĸ��

char findTheDifference(string s, string t) {
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());   //�������ַ����������򼴿ɣ���ͬ����һλ������ӵ��ַ�
	int i = 0;
	while (i < s.size()) {
		if (s[i] == t[i]) {
			i++;
		}
		else {
			return t[i];
		}
	}
	return t[i];
}

int main(void)
{
	string s1 = "abcde";
	string s2 = "bdacae";
	cout << findTheDifference(s1, s2) << endl;
	system("pause");
	return 0;
}