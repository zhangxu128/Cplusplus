//#include<stdio.h>
//#include<stdlib.h>
//
//
//int main()
//{
//	/*ţţ��һ����Сд��ĸ��ɵ��ַ���s, ��s�п�����һЩ��ĸ�ظ����֡�
//		������"banana"��, ��ĸ'a'����ĸ'n'�ֱ���������κ����Ρ�
//		����ţţ��ϲ���ظ�������ͬһ����ĸ, ��ֻ�뱣����һ�γ��ֲ�ɾ����������ֵ���ĸ��
//		�����ţţ��ɶ�s�Ĳ�����*/
//	char string[] = {"asdbasddav"};
//	char* p = getStr(string,sizeof(string));
//	printf("%s\n",p);
//	system("pause");
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<bits.h>
#include<cstring>
#include<vector>

using namespace std;
int main() {
	char s[100];
	while (scanf("%s", s) != EOF) {
		int s1[26];
		std::vector<char> v;
		memset(s1, 0, sizeof(s1));
		int len = strlen(s);
		for (int i = 0; i < len; i++) {
			int temp = s[i] - 'a';
			if (s1[temp] == 0) {
				s1[temp] = 1;
				v.push_back(s[i]);
			}
		}
		for (int i = 0; i < v.size(); i++) {
			cout << v[i];
		}
		cout << endl;
	}
	return 0;
}