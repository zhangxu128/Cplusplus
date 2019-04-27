//题目描述
//给定无序整数序列，求连续子串最大和，例如{ -23 17 - 7 11 - 2 1 - 34 }，子串为{ 17,-7,11 }，最大和为21
//输入描述 :
//输入为整数序列，数字用空格分隔，如： - 23 17 - 7 11 - 2 1 - 34
//输出描述 :
//	输出为子序列的最大和：21
//	示例1
//	输入
//	- 23 17 - 7 11 - 2 1 - 34
//	输出
//	21


//典型题目，因为是连续子串，因此我们根据当前位置是从头还是连续之前的来区分即可
#include<iostream>
#include<vector>
using namespace std;
int main(void)
{
	int tmp;
	vector<int> num;
	while (cin >> tmp)
	{
		num.push_back(tmp);
	}
	int begin = 0, end = 1;
	int max = num[0], sum = num[0];
	while (end < num.size())
	{
		sum += num[end];
		if (sum < 0)
		{
			begin = end + 1;
			sum = 0;
		}
		else if (sum > max)
		{
			max = sum;
		}
		end++;
	}
	cout << max << endl;
	system("pause");
	return 0;
}
