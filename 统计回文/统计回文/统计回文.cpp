#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//��Ŀ����   
//�����Ĵ�����һ�������ͷ�����һ�����ַ��������硰level�����ߡ�noon���ȵȾ��ǻ��Ĵ���
//�����ǳ�ϲ������ӵ�жԳ����Ļ��Ĵ������յ�ʱ�����õ���������ֱ����ַ���A���ַ���B��
//�������ǳ�������û�а취���ַ���B�����ַ���Aʹ�������ַ�����һ�����Ĵ�������ܻ���������
//������Ѱ���ж����ֲ���취����ʹ�´���һ�����Ĵ�������ַ���B�����λ�ò�ͬ�Ϳ���Ϊ��һ���İ취��
//���磺
//A = ��aba����B = ��b����������4�ְ�B����A�İ취��
//* ��A�ĵ�һ����ĸ֮ǰ: "baba" ���ǻ���
//* �ڵ�һ����ĸ��a��֮�� : "abba" �ǻ���
//* ����ĸ��b��֮�� : "abba" �ǻ���
//* �ڵڶ�����ĸ'a'֮�� "abab" ���ǻ���
//�������������Ĵ�Ϊ2
//�������� :
//ÿ���������ݹ����С�
//��һ��Ϊ�ַ���A
//�ڶ���Ϊ�ַ���B
//�ַ������Ⱦ�С��100��ֻ����Сд��ĸ
//������� :
//���һ�����֣���ʾ���ַ���B�����ַ���A֮�󹹳�һ�����Ĵ��ķ�����
//ʾ��1
//����
//aba
//b
//���
//2

//�ж��ǲ��ǻ��Ĵ�
bool isLoop(string s) {
	string str;
	for (int i = 0; i < s.size(); i++) {
		str.push_back(s[s.size() - 1 - i]);
	}
	if (s == str) {
		return true;
	}
	return false;
}  
int insert(string s1, string s2) {
	int size1 = s1.size();
	int size2 = s2.size();
	int count = 0;
	string s;
	for (int i = 1; i < size1; i++) {
		int j;
		for (j = 0; j < i; j++) {
			s.push_back(s1[j]);
		}
		for (int j = 0; j < size2; j++) {
			s.push_back(s2[j]);
		}
		for (j = i; j < size1; j++) {
			s.push_back(s1[j]);
		}
		if (isLoop(s)) {
			count++;
		}
		s.resize(0);
	}
	s = s1 + s2;
	if (isLoop(s))count++;
	s = s2 + s1;
	if (isLoop(s))count++;
	return count;
}

int main(void) {
	string A;
	cin >> A;
	string B;
	cin >> B;
	int count = insert(A, B);
	cout << count << endl;
	system("pause");
	return 0;
}