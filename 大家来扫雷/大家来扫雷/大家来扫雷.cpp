//题目描述
//小M最近爱上了扫雷游戏，就是在一个n*m的区域中，有地雷，每一个方格上都有一个数字s，表示在这个方格周围有s颗雷，现在给你一张表明地雷的图，并且指定一个位置点开，请输出点开后的数字情况，若点开的地方的数字为0，则向该方格周围扩展，直到遇到数字或者地图边界为止，若点开的地方为地雷, 那么直接输出"GG"。
//周围指的是上，左上，左，左下，下，右下，右，右上八个方向。
//输入描述 :
//第一行有两个数字n和m(2 <= n, m <= 1000)，表示地图的大小，第二行有两个整数x和y(1 <= x <= n, 1 <= y <= m)，表示点击第x行y列的方格，接下来的是一个n行m列的一个矩阵，表示地图，其中.表示空地，*表示地雷。
//输出描述 :
//如果点开的地方为地雷直接输出"GG"。否则输出点击指定位置后的地图，"."表示未点开的空地，"*"表示地雷，数字表示在该方格周围的地雷数目。
//示例1
//输入
//3 4
//1 1
//....
//..*.
//....
//输出
//01..
//01 * .
//01..

/*
连通图的遍历
*/


#include <iostream>
#include <vector>

using namespace std;

static const auto _ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return nullptr;
}();

vector<vector<char>> grid;

class Solution {
public:
	char countMines(int x, int y) {
		int row = grid.size();
		int col = grid[0].size();
		int num = 0;
		vector<pair<int, int>> neighbors{ {x - 1, y - 1}, {x - 1, y}, {x - 1, y + 1},
		{x, y - 1}, {x, y + 1}, {x + 1, y - 1}, {x + 1, y}, {x + 1, y + 1} }; //eight neighors

		for (auto& n : neighbors)
			if (n.first >= 0 && n.first < row && n.second >= 0 && n.second < col && grid[n.first][n.second] == '*')
				++num;

		return '0' + num;
	}
	void explore(int x, int y)
	{
		int row = grid.size();
		int col = grid[0].size();
		if (x < 0 || x >= row || y < 0 || y >= col || grid[x][y] != '.')
			return;
		char num = countMines(x, y);
		if (num != '0')
			grid[x][y] = num;
		else
		{
			grid[x][y] = '0';
			explore(x - 1, y - 1);
			explore(x - 1, y);
			explore(x - 1, y + 1);
			explore(x, y - 1);
			explore(x, y + 1);
			explore(x + 1, y - 1);
			explore(x + 1, y);
			explore(x + 1, y + 1);
		}
	}

	bool exploreMines(int x, int y)
	{
		int row = grid.size();
		if (row == 0)
			return true;
		int col = grid[0].size();
		if (col == 0)
			return true;
		if (x < 0 || x >= row || y < 0 || y >= col)
			return true;
		if (grid[x][y] == '*')
			return false;

		explore(x, y);
		return true;
	}
};

int main()
{
	int n, m; // n - row, m - column
	cin >> n >> m;
	int x, y; // start point grid[x-1][y-1]
	cin >> x >> y;
	char tmp;
	for (int i = 0; i < n; ++i)
	{
		vector<char> vTmp;
		for (int j = 0; j < m; ++j)
		{
			cin >> tmp;
			vTmp.push_back(tmp);
		}
		grid.push_back(vTmp);
	}
	Solution solution;
	if (solution.exploreMines(x - 1, y - 1))
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
				cout << grid[i][j];
			cout << endl;
		}
	else
		cout << "GG" << endl;
}