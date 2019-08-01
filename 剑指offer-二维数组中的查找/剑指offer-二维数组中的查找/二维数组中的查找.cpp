//题目描述
//在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
//每一列都按照从上到下递增的顺序排序。
//请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

#include <iostream>
#include <vector>

using namespace std;

bool Find(int target, vector<vector<int> > array) {
	if (array.empty()) {
		return false;
	}
	int row = 0;
	int col = array[0].size() - 1;
	while (row < array.size() && col < array[0].size()) {
		if (array[row][col] == target) {
			return true;
		}
		else if (array[row][col] > target) {
			col--;
		}
		else {
			row++;
		}
	}
	return false;
}

int main(void) {
	int target;
	cin >> target;

	int n;
	int m;
	cin >> n >> m;
	vector<vector<int>> vv(n,vector<int>v(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> vv[i][j];
		}
	}
	cout << Find(target, vv);
	system("pause");
	return 0;
}