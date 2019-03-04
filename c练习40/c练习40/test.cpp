//#include<stdio.h>
//#include<stdlib.h>
//
//
//int main()
//{
//	/*牛牛有一个由小写字母组成的字符串s, 在s中可能有一些字母重复出现。
//		比如在"banana"中, 字母'a'和字母'n'分别出现了三次和两次。
//		但是牛牛不喜欢重复。对于同一个字母, 他只想保留第一次出现并删除掉后面出现的字母。
//		请帮助牛牛完成对s的操作。*/
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