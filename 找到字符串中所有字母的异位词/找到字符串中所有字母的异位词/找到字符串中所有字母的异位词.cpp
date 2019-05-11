//给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。
//字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。
//说明：
//字母异位词指字母相同，但排列不同的字符串。
//不考虑答案输出的顺序。
//示例 1:
//输入:
//s: "cbaebabacd" p : "abc"
//
//	输出 :
//	[0, 6]


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

vector<int> findAnagrams(string s, string p) {
	if (s.size() < p.size())
		return {};
	int l = 0, r = -1;
	vector<int> freq_s(26, 0), freq_p(26, 0), res;
	// 初始化代码值
	for (int i = 0; i < p.size(); i++) {
		freq_p[p[i] - 'a']++;
		freq_s[s[++r] - 'a']++;
	}
	if (freq_s == freq_p)
		res.push_back(l);
	// 固定长度的滑动窗口
	while (r < s.size() - 1) {
		freq_s[s[++r] - 'a']++;
		freq_s[s[l++] - 'a']--;
		if (freq_s == freq_p)
			res.push_back(l);
	}
	return res;
}
int main(void) {
	string s;
	cout << "请输入字符串1" << endl;
	cin >> s;
	string p;
	cout << "请输入字符串2" << endl;
	cin >> p;
	cout << "异位词出现的位置如下" << endl;
	vector<int> v = findAnagrams(s, p);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}