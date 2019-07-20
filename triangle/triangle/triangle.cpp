//Ã‚ƒø√Ë ˆ
//
//Given a triangle, find the minimum path sum from top to bottom.Each step you may move to adjacent numbers on the row below.
//For example, given the following triangle
//[
//	[2],
//	[3, 4],
//	[6, 5, 7],
//	[4, 1, 8, 3]
//]
//
//The minimum path sum from top to bottom is11(i.e., 2 + 3 + 5 + 1 = 11).
//Note:
//Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minimumTotal(vector<vector<int> > &triangle) {
	if (triangle.empty())
		return 0;

	vector<vector<int>>  vv(triangle);
	int row = vv.size() - 1;
	for (int i = row - 1; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			vv[i][j] = vv[i][j] + min(vv[i + 1][j + 1], vv[i + 1][j]);
		}
	}
	return vv[0][0];
}

int main(void) {

	int n;
	cin >> n;
	vector<vector<int>> vv(n, vector<int>(n+1));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> vv[i][j];
		}
	}

	cout << minimumTotal(vv) << endl;

	system("pause");
	return 0;
}