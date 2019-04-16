#include <string>
#include <iostream>
using namespace std;

//题目描述
//给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数
//输入描述 :
//输入为一行，M(32位整数)、N(2 ≤ N ≤ 16)，以空格隔开。
//输出描述 :
//为每个测试实例输出转换后的数，每个输出占一行。如果N大于9，
//则对应的数字规则参考16进制（比如，10用A表示，等等）
int main() {
	string s = "", table = "0123456789ABCDEF";
	int m, n;
	cin >> m >> n;
	while (m) {
		if (m < 0) {
			m = -m;
			cout << "-";
		}
		s = table[m%n] + s;
		m /= n;
	}
	cout << s << endl;
	system("pause");
	return 0;
}