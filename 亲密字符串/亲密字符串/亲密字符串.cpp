//给定两个由小写字母构成的字符串 A 和 B ，
//只要我们可以通过交换 A 中的两个字母得到与 B 相等的结果，就返回 true ；否则返回 false 。
//示例 1：
//输入： A = "ab", B = "ba"
//输出： true
//示例 2：
//输入： A = "ab", B = "ab"
//输出： false
//示例 3:
//输入： A = "aa", B = "aa"
//输出： true
//示例 4：
//输入： A = "aaaaaaabc", B = "aaaaaaacb"
//输出： true
//示例 5：
//输入： A = "", B = "aa"
//输出： false
//提示：
//0 <= A.length <= 20000
//0 <= B.length <= 20000
//A 和 B 仅由小写字母构成。

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

bool buddyStrings(string A, string B) {
	if ((A.empty() && B.empty()) || (A.length() != B.length())) {
		return false;
	}
	vector<int> vec;
	for (int i = 0; i < A.length(); i++) {
		if (A[i] != B[i]) {
			vec.push_back(i);
		}
		if (vec.size() > 2) {
			return false;
		}
	}
	if (A != B) {
		char c;
		c = A[vec[0]];
		A[vec[0]] = A[vec[1]];
		A[vec[1]] = c;
		// swap(A[vec[0]],A[vec[1]]);
		return A == B;
	}
	else {
		map<char, int> m;
		for (int j = 0; j < A.size(); j++) {
			m[A[j]]++;
			if (m[A[j]] >= 2) {
				return true;
			}
		}
		return false;
	}
	return false;
}

int main(void) {
		
	string s1;
	string s2;
	cin >> s1 >> s2;
	if (buddyStrings(s1, s2)) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	system("pause");
	return 0;
}