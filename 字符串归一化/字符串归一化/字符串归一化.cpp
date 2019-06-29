//题目描述
//通过键盘输入一串小写字母(a~z)组成的字符串。
//请编写一个字符串归一化程序，统计字符串中相同字符出现的次数，并按字典序输出字符及其出现次数。
//例如字符串"babcc"归一化后为"a1b2c2"
//输入描述:
//每个测试用例每行为一个字符串，以'\n'结尾，例如cccddecca
//输出描述 :
//输出压缩后的字符串ac5d2e
//示例1
//输入
//dabcab
//输出
//a2b2c1d1

#include <iostream>
#include<stdio.h>
#define SIZE 128
using namespace std;
int main() {
	int cnt[26] = { 0 }, i = 0;
	char a[SIZE];
	fgets(a, SIZE, stdin);
	while (a[i] != '\n')
	{
		cnt[a[i] - 'a']++;
		i++;
		if (i == SIZE) {
			i = 0;
			fgets(a, SIZE, stdin);
		}
	}
	for (int i = 0; i < 26; i++)
		if (cnt[i] != 0)
			cout << (char)(i + 'a') << cnt[i];
	system("pause");
	return 0;
}
