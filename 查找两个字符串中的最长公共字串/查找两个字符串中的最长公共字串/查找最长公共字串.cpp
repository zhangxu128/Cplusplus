//查找两个字符串中的最长公共字串，若有多个，则输出短字符串中最先出现的

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		if (str1.size() > str2.size())
			swap(str1, str2);

		int len1 = str1.size(), len2 = str2.size(), i, j, start = 0, max = 0;

		vector<vector<int>>dp(len1 + 1, vector<int>(len2 + 1, 0));
		for (i = 1; i <= len1; i++)
			for (j = 1; j <= len2; j++)
			{
				if (str1[i - 1] == str2[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				if (dp[i][j] > max)
				{
					max = dp[i][j];
					start = i - max;
				}
			}
		cout << str1.substr(start, max) << endl;
	}
	return 0;
}