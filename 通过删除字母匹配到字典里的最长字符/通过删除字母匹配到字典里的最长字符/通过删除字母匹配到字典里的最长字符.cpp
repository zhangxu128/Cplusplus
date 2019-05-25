//给定一个字符串和一个字符串字典，找到字典里面最长的字符串，该字符串可以通过删除给定字符串的某些字符来得到。如果答案不止一个，返回长度最长且字典顺序最小的字符串。如果答案不存在，则返回空字符串。
//
//示例 1:
//
//输入:
//s = "abpcplea", d = ["ale", "apple", "monkey", "plea"]
//
//输出 :
//	"apple"
//	示例 2 :
//
//	输入 :
//	s = "abpcplea", d = ["a", "b", "c"]
//
//	输出 :
//	"a"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


//排序后按个与字典字符比较
string findLongestWord(string s, vector<string>& d) {
	sort(d.begin(), d.end(), [](string &a, string &b) {
		if (a.size() != b.size())
			return a.size() > b.size();
		else
			return a < b;
	});

	for (int i = 0; i < d.size(); i++) {
		int j = 0, k = 0;
		while (k < s.size()) {
			if (s[k] == d[i][j])
				k++, j++;
			else
				k++;
		}
		if (j == d[i].size())
			return d[i];
	}
	return "";
}

int main(void) {
	cout << "输入数组元素个数" << endl;
	int n;
	cin >> n;
	cout << "输入数组元素字符串" << endl;
	vector<string> v(n);
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}
	cout << "输入字典字符串" << endl;
	string str;
	cin >> str;
	cout << "最长字符串为" << findLongestWord(str,v) << endl;
	system("pause");
	return 0;
}