#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <sstream>
#include <stdlib.h>
#include <algorithm>
#include <limits.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define ll long long

using namespace std;

int main() {
	int m, n;
	scanf("%d%d", &m, &n);
	vector<vector<int>> nums(m + 1, vector<int>(n + 1, 0)), v(m + 1, vector<int>(n + 1, 0)), dp(m + 1, vector<int>(n + 1, 1));

	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &nums[i][j]);

	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++) {
			if (i == 1 || j == 1) {
				if (i == 1) {
					dp[i][j] = max(dp[i][j - 1], -(v[i][j - 1] + nums[i][j]) + 1);
					v[i][j] = v[i][j - 1] + nums[i][j];
				}
				else {
					dp[i][j] = max(dp[i - 1][j], -(v[i - 1][j] + nums[i][j]) + 1);
					v[i][j] = v[i - 1][j] + nums[i][j];
				}
			}
			else {
				dp[i][j] = min(max(dp[i][j - 1], -(v[i][j - 1] + nums[i][j]) + 1), max(dp[i - 1][j], -(v[i - 1][j] + nums[i][j]) + 1));
				v[i][j] = max(v[i][j - 1] + nums[i][j], v[i - 1][j] + nums[i][j]);
			}
			//cout << i << " " << j << " " << dp[i][j] << endl;
		}
	
	printf("%d\n", dp[m][n]);
	system("pause");

	return 0;
}
