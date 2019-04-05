#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//给定两个字符串 s 和 t，它们只包含小写字母。
//字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母
//请找出在 t 中被添加的字母。
//示例 :
//输入：
//s = "abcd"
//t = "abcde"
//输出：
//e
//解释：
//'e' 是那个被添加的字母。

char findTheDifference(string s, string t) {
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());   //将两个字符串进行排序即可，不同的哪一位就是添加的字符
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