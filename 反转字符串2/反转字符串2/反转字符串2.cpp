#include <iostream>
#include <string>

//����һ���ַ�����һ������ k������Ҫ�Դ��ַ�����ͷ�����ÿ�� 2k ���ַ���ǰk���ַ����з�ת��
//���ʣ������ k ���ַ�����ʣ�������ȫ����ת�������С�� 2k �����ڻ���� k ���ַ�����תǰ k ���ַ���
//����ʣ����ַ�����ԭ����
//ʾ�� :
//����: s = "abcdefg", k = 2
//	��� : "bacdfeg"
//	Ҫ�� :
//	���ַ���ֻ����Сд��Ӣ����ĸ��
//	�����ַ����ĳ��Ⱥ� k ��[1, 10000]��Χ�ڡ�

using namespace std;

//���÷�ת������ԭ�ط�ת
string reverseStr(string s, int k) {
	int p = 0;
	while (s.size() - p >= 2 * k) {
		reverse(s.begin() + p, s.begin() + p + k);
		p += (2 * k);
	}
	if (s.size() - p >= k) reverse(s.begin() + p, s.begin() + p + k);
	else reverse(s.begin() + p, s.end());
	return s;
}

int main(void){

	cout << "������һ���ַ���s:" << endl;
	string s;
	cin >> s;
	cout << "�����뷴ת����" << endl;
	int k;
	cin >> k;
	cout << "�����ɷ�ת�ַ�����Ϊ��" << reverseStr(s, k) << endl;
	system("pause");
	return 0;
}