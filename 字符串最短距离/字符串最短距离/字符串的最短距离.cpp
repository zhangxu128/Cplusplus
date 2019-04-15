#include<iostream>
#include<vector>
using namespace std;

//给定一个字符串 S 和一个字符 C。返回一个代表字符串 S 中每个字符到字符串 S 中的字符 C 的最短距离的数组。
//示例 1:
//  输入: S = "loveleetcode", C = 'e'
//	输出 : [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
//	说明 :
//	字符串 S 的长度范围为[1, 10000]。
//	C 是一个单字符，且保证是字符串 S 里的字符。
//	S 和 C 中的所有字母均为小写字母。

class Solution {
public:
	int min(int i, int j) {
		return i < j ? i : j;
	}
	vector<int> shortestToChar(string S, char C) {
		int *array = new int[S.size()]{ 0 };
		int preC = -1;
		//先找到 C 的位置, 再对 C 前面的位置赋值
		for (int i = 0; i < S.size(); i++) {
			if (C == S[i]) {
				int j = i - 1;
				for (; j > preC; j--) {
					array[j] = preC == -1 ? i - j : min(j - preC, i - j);
				}
				preC = i;
			}
		}
		//最后一个 C 后面的位置赋值
		for (int i = preC + 1; i < S.size(); i++) {
			array[i] = i - preC;
		}
		vector<int>v(array, array + S.size());
		return v;
	}
};

int main() {

	string str = "abdfajf";
	char c = 'f';
	Solution s;
	vector<int> v = s.shortestToChar(str, c);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	system("pause");
	return 0;
}