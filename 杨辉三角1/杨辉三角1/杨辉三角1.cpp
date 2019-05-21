//给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
//在杨辉三角中，每个数是它左上方和右上方的数的和。
//输入: 5
//	输出 :
//	[
//		[1],
//		[1, 1],
//		[1, 2, 1],
//		[1, 3, 3, 1],
//		[1, 4, 6, 4, 1]
//	]

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows) {
	vector<vector<int>> v(numRows, vector<int>());
	for (int i = 0; i < v.size(); i++) {
		v[i].resize(i + 1, 1);
		for (int j = 1; j < i; j++) {
			v[i][j] = v[i - 1][j] + v[i - 1][j - 1];
		}
	}
	return v;
}

int main(void) {

	cout << "请输入杨辉三角的行数n:";
	int n;
	cin >> n;

	vector<vector<int>> v = generate(n);
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}