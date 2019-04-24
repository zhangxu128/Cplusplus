#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//题目描述
//牛牛有一个正整数x, 牛牛需要把数字x中的数位进行重排得到一个新数(不同于x的数),
//牛牛想知道这个新数是否可能是原x的倍数。请你来帮他解决这个问题。
//输入描述 :
//输入包括t + 1行, 第一行包括一个整数t(1 ≤ t ≤ 10),
//接下来t行, 每行一个整数x(1 ≤ x ≤ 10 ^ 6)
//输出描述 :
//	对于每个x, 如果可能重排之后变为自己的倍数输出"Possible", 否则输出"Impossible".
//	示例1
//	输入
//	2
//	14
//	1035
//	输出
//	Impossible
//	Possible


int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int ori = stoi(s), flag = 0;
		sort(s.begin(), s.end());

		do {
			int num = stoi(s);
			if (num != ori && num%ori == 0) {
				flag = 1;
				break;
			}
		} while (next_permutation(s.begin(), s.end()));
		if (flag)cout << "Possible" << endl;
		else cout << "Impossible" << endl;
	}
	system("pause");
	return 0;
}
