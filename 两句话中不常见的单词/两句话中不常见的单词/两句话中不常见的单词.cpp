//给定两个句子 A 和 B 。 （句子是一串由空格分隔的单词。每个单词仅由小写字母组成。）
//如果一个单词在其中一个句子中只出现一次，在另一个句子中却没有出现，那么这个单词就是不常见的。
//返回所有不常用单词的列表。
//您可以按任何顺序返回列表。
//示例 1：
//输入：A = "this apple is sweet", B = "this apple is sour"
//输出：["sweet", "sour"]
//示例 2：
//输入：A = "apple apple", B = "banana"
//输出：["banana"]

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
using namespace std;

vector<string> uncommonFromSentences(string A, string B) {
	unordered_map<string, int> m;
	string temp;
	stringstream is(A);
	while (is >> temp) m[temp]++;
	is = stringstream(B);
	while (is >> temp) m[temp]++;
	vector<string> ret;
	for (unordered_map<string, int>::iterator i = m.begin(); i != m.end(); i++) {
		if (i->second == 1)
			ret.push_back(i->first);
	}
	return ret;
}

int main(void) {

	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);

	vector<string> ret = uncommonFromSentences(s1, s2);

	for (auto & e : ret) {
		cout << e << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}