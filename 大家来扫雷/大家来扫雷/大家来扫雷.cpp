//��Ŀ����
//СM���������ɨ����Ϸ��������һ��n*m�������У��е��ף�ÿһ�������϶���һ������s����ʾ�����������Χ��s���ף����ڸ���һ�ű������׵�ͼ������ָ��һ��λ�õ㿪��������㿪���������������㿪�ĵط�������Ϊ0������÷�����Χ��չ��ֱ���������ֻ��ߵ�ͼ�߽�Ϊֹ�����㿪�ĵط�Ϊ����, ��ôֱ�����"GG"��
//��Χָ�����ϣ����ϣ������£��£����£��ң����ϰ˸�����
//�������� :
//��һ������������n��m(2 <= n, m <= 1000)����ʾ��ͼ�Ĵ�С���ڶ�������������x��y(1 <= x <= n, 1 <= y <= m)����ʾ�����x��y�еķ��񣬽���������һ��n��m�е�һ�����󣬱�ʾ��ͼ������.��ʾ�յأ�*��ʾ���ס�
//������� :
//����㿪�ĵط�Ϊ����ֱ�����"GG"������������ָ��λ�ú�ĵ�ͼ��"."��ʾδ�㿪�Ŀյأ�"*"��ʾ���ף����ֱ�ʾ�ڸ÷�����Χ�ĵ�����Ŀ��
//ʾ��1
//����
//3 4
//1 1
//....
//..*.
//....
//���
//01..
//01 * .
//01..

/*
��ͨͼ�ı���
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