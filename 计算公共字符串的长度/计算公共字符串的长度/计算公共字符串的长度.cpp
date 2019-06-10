//计算公共字符串的长度，不区分大小写

#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		int len1 = str1.size();
		int len2 = str2.size();
		int max = 0;
		int tmp[100][100];

		for (int i = 0; i < len1; i++)
		{
			for (int j = 0; j < len2; j++)
			{
				if (str1[i] == str2[j])
				{
					if (i == 0 || j == 0)
					{
						tmp[i][j] = 1;
					}
					else
					{
						tmp[i][j] = tmp[i - 1][j - 1] + 1;
					}
				}
				else
				{
					tmp[i][j] = 0;
				}
				if (tmp[i][j] > max)
						max = tmp[i][j];
			}
		}
		cout << max << endl;
	}
	return 0;
}
