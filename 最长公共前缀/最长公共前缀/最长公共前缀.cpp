#include <iostream>
#include <string >
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
	if (strs.empty()) {
		return "";
	}
	// 终止条件：任意一个字符串到达结尾，或者遇到不同的字符        
	int i_char = 0;
	while (true) {
		// 检查是否越界，以及当前位字符是否相同
		for (int i_strs = 0; i_strs < strs.size(); i_strs++) {
			if (
				i_char == strs[i_strs].size() // 是否越界
				||
				strs[i_strs][i_char] != strs[0][i_char] // 当前位字符是否相同
				) 
			{
				return strs[i_strs].substr(0, i_char);
			}
		}
		i_char++;
	}
}


int main(void) {
	
	string s;
	vector<string> v;
	
	int n;//输入n个字符串
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}

	string ret = longestCommonPrefix(v);

	cout << ret << endl;
	system("pause");
	return 0;
}