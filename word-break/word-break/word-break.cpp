//ÌâÄ¿ÃèÊö
//
//Given a string s and a dictionary of words dict, determine if s can be segmented into a s
//pace - separated sequence of one or more dictionary words.
//For example, given
//s = "leetcode",
//dict = ["leet", "code"].
//Return true because"leetcode"can be segmented as"leet code".

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

bool wordBreak(string s, unordered_set<string> &dict) {
	vector<bool> v(s.size() + 1, false);
	v[0] = true;
	for (int i = 1; i <= s.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (v[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
				v[i] = true;
				break;
			}
		}
	}
	return v[s.size()];
}

int main(void) {

	string s,str;
	cin >> s;

	int n;
	cin >> n;
	unordered_set<string> set(n);
	for(int i = 0 ; i < n; i++){
		cin >> str;
		set.insert(str);
	}
	cout << wordBreak(s, set) << endl;;

	system("pause");
	return 0;
}
