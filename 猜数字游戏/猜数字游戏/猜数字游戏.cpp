//你正在和你的朋友玩 猜数字（Bulls and Cows）游戏：你写下一个数字让你的朋友猜。
//每次他猜测后，你给他一个提示，告诉他有多少位数字和确切位置都猜对了（称为“Bulls”, 公牛），
//有多少位数字猜对了但是位置不对（称为“Cows”, 奶牛）。你的朋友将会根据提示继续猜，直到猜出秘密数字。
//请写出一个根据秘密数字和朋友的猜测数返回提示的函数，用 A 表示公牛，用 B 表示奶牛。
//请注意秘密数字和朋友的猜测数都可能含有重复数字
//示例 1
//输入: secret = "1807", guess = "7810"
//	输出 : "1A3B"
//	解释 : 1 公牛和 3 奶牛。公牛是 8，奶牛是 0, 1 和 7。
//	示例 2 :
//	输入 : secret = "1123", guess = "0111"
//	输出 : "1A1B"
//	解释 : 朋友猜测数中的第一个 1 是公牛，第二个或第三个 1 可被视为奶牛。
//	说明 : 你可以假设秘密数字和朋友的猜测数都只包含数字，并且它们的长度永远相等。


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//先遍历一遍找公牛，将不同为放入容器中
//然后排序后直接比较找母牛
string getHint(string secret, string guess) {
	int cntA = 0;
	int cntB = 0;
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < secret.size(); i++) {
		if (secret[i] == guess[i]) {
			cntA++;
		}
		else {
			v1.push_back(secret[i]);
			v2.push_back(guess[i]);
		}
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	while (!v1.empty() && !v2.empty())
	{
		if (v1[v1.size() - 1] == v2[v2.size() - 1])
		{
			cntB++;
			v1.pop_back();
			v2.pop_back();
		}
		else if (v1[v1.size() - 1] > v2[v2.size() - 1])
		{
			v1.pop_back();
		}
		else
		{
			v2.pop_back();
		}
	}
	return to_string(cntA) + "A" + to_string(cntB) + "B";
}

int main(void) {

	string s1, s2;
	cin >> s1 >> s2;
	cout << getHint(s1, s2) << endl;
	system("pause");
	return 0;
}