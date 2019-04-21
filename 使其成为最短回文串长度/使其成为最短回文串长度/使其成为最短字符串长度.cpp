#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//题目描述
//京京和东东是好朋友。东东很喜欢回文。回文是指从前往后读和从后往前读是一样的词语。
//京京准备给东东一个惊喜, 先取定一个字符串s, 然后在后面附上0个或者更多个字母形成回文,
//京京希望这个回文越短越好。请帮助京京计算他能够得到的最短的回文长度。

// 输入  abab
// 输出  5

bool isloop(string s) {
	string str = s;
	reverse(s.begin(), s.end());
	if (str == s) {
		return true;
	}
	return false;
}

int main(void) {
	string s;
	int count = 0;
	
	while (cin >> s) {
		if (isloop(s)) {
			cout << s.size() << endl;
			continue;
		}
		for (int i = 1; i < s.size(); i++) {
			string str(s.begin() + i, s.end());
			if (isloop(str)) {
				count = i;
				break;
			}
		}
		cout << count + s.size() << endl;
	}
	system("pause");
	return 0;
}