//回旋镖定义为一组三个点，这些点各不相同且不在一条直线上。
//给出平面上三个点组成的列表，判断这些点是否可以构成回旋镖。
//示例 1：
//输入：[[1, 1], [2, 3], [3, 2]]
//输出：true
//示例 2：
//输入：[[1, 1], [2, 2], [3, 3]]
//输出：false
//提示：
//points.length == 3
//points[i].length == 2
//0 <= points[i][j] <= 100

#include <iostream>
#include <vector>


using namespace std;

//利用向量的方法判断三点一线是否成立
bool isBoomerang(vector<vector<int>>& points) {
	int x1 = points[0][0];
	int y1 = points[0][1];
	int x2 = points[1][0];
	int y2 = points[1][1];
	int x3 = points[2][0];
	int y3 = points[2][1];

	return (y2 - y1)*(x3 - x2) != (y3 - y2)*(x2 - x1);
}
int main(void) {
	vector<int> tmp(2);
	vector<vector<int>> v(3,tmp);
	int num;
	for (int i = 0; i < v.size(); i++) {
	
		for (int j = 0; j < v[i].size(); j++) {
			cin >> num;
			v[i][j] = num;
		}
	}

	if (isBoomerang(v)) {
		cout << "三点一线,不能构成回旋镖" << endl;
	}
	else {
		cout << "三点不在一线，可以构成回旋镖" << endl;
	}
	system("pause");
	return 0;
}