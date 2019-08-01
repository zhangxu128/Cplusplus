//��Ŀ����
//��һ����ά�����У�ÿ��һά����ĳ�����ͬ����ÿһ�ж����մ����ҵ�����˳������
//ÿһ�ж����մ��ϵ��µ�����˳������
//�����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������

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