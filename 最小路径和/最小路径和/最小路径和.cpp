//给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
//说明：每次只能向下或者向右移动一步。
//示例 :
//输入:
//[
//	[1, 3, 1],
//	[1, 5, 1],
//	[4, 2, 1]
//]
//输出 : 7
//	解释 : 因为路径 1→3→1→1→1 的总和最小。

#include <iostream>
#include <vector>
using namespace std;

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

//以空间换时间，用二维数组存储到该点的最短距离
int minPathSum(vector<vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			if (i == 0 && j == 0) continue;
			if (i == 0)
				grid[i][j] += grid[i][j - 1];
			else if (j == 0)
				grid[i][j] += grid[i - 1][j];
			else
				grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
		}

	return grid[m - 1][n - 1];
}



int main(void) {
	cout << "请输入m*n的网格" << endl;
	cout << "请输入行数" << endl;
	int m;
	cin >> m;
	cout << "请输入列数" << endl;
	int n;
	cin >> n;

	vector<vector<int>>v;
	vector<int> tmp;
	
	int num;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> num;
			tmp.push_back(num);
		}
		v.push_back(tmp);
	}
	int ret = minPathSum(v);
	cout << ret << endl;
	system("pause");
	return 0;
}