#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int lcs(string m, string n) {
	int mLength = m.length();
	int nLength = n.length();
	vector<vector<int>> vv(mLength+1, vector<int>(nLength+1));
	for (int i = 1; i <= mLength; i++) {
		for (int j = 1; j <= nLength; j++) {
			vv[i][j] = max(vv[i - 1][j], vv[i][j - 1]);
			if (m[j - 1] == n[j - 1]) {
				vv[i][j] = max(vv[i][j], vv[i - 1][j - 1] + 1);

			}

		}

	}
	return vv[mLength][nLength];
}

int main(void) {

	string m, n;
	cin >> m >> n;
	cout << lcs(m, n) << endl;
	system("pause");
	return 0;
}