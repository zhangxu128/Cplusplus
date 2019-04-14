#include<iostream>
#include<vector>

using namespace std;

//解释:
//唯一的编码方式是一个两比特字符和一个一比特字符。所以最后一个字符是一比特字符。
//示例 2 :
//	输入 :
//	bits = [1, 1, 1, 0]
//	输出 : False
//	解释 :
//唯一的编码方式是两比特字符和两比特字符。所以最后一个字符不是一比特字符。
//注意 :
//1 <= len(bits) <= 1000.
//bits[i] 总是0 或 1.

bool isOneBitCharacter(vector<int>& bits) {
	int n = bits.size();
	int i = 0;
	while (i < n) {
		if (i == n - 1)
			return true;
		if (bits[i] == 1)
			i += 2;
		else
			i++;
	}
	return false;
}

int main(void) {

	int n;
	cin >> n;
	vector<int>v;
	int tmp = 0;
	while (n--) {
		cin >> tmp;
		v.push_back(tmp);
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;

	cout << isOneBitCharacter(v) << endl;
	system("pause");
	return 0;
}