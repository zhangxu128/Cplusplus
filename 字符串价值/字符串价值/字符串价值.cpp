//��Ŀ����
//��һ����Ȥ���ַ�����ֵ���㷽ʽ : ͳ���ַ�����ÿ���ַ����ֵĴ���, Ȼ���������ַ�������ƽ������Ϊ�ַ����ļ�ֵ
//	���� : �ַ���"abacaba", �������4��'a', 2��'b', 1��'c', ��������ַ����ļ�ֵΪ4 * 4 + 2 * 2 + 1 * 1 = 21
//	ţţ��һ���ַ���s, �����������s���Ƴ����k���ַ�, ���Ŀ�����õõ����ַ����ļ�ֵ��С��
//	�������� :
//�����������, ��һ��һ���ַ���s, �ַ���s�ĳ���length(1 �� length �� 50), ����ֻ����Сд��ĸ('a' - 'z')��
//�ڶ��а���һ������k(0 �� k �� length), �������Ƴ����ַ�������
//������� :
//���һ������, ��ʾ�õ�����С��ֵ
//ʾ��1
//����
//aba
//1
//���
//2

#include <string>
#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	string s;
	int k;
	cin >> s >> k;
	int alph[26] = { 0 };
	for (int i = 0; i < s.size(); i++) {
		alph[s[i] - 'a']++;
	}
	sort(alph, alph + 26);
	for (int i = 0; i < k; i++) {
		alph[25]--;
		sort(alph, alph + 26);
	}
	int value = 0;
	for (int i = 0; i < 26; i++) {
		value += alph[i] * alph[i];
	}
	cout << value << endl;
	system("pause");
	return 0;
}