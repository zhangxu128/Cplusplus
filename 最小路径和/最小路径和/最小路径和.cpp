//����һ�������Ǹ������� m x n �������ҳ�һ�������Ͻǵ����½ǵ�·����ʹ��·���ϵ������ܺ�Ϊ��С��
//˵����ÿ��ֻ�����»��������ƶ�һ����
//ʾ�� :
//����:
//[
//	[1, 3, 1],
//	[1, 5, 1],
//	[4, 2, 1]
//]
//��� : 7
//	���� : ��Ϊ·�� 1��3��1��1��1 ���ܺ���С��

#include <iostream>
#include <vector>
using namespace std;

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

//�Կռ任ʱ�䣬�ö�ά����洢���õ����̾���
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
	cout << "������m*n������" << endl;
	cout << "����������" << endl;
	int m;
	cin >> m;
	cout << "����������" << endl;
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