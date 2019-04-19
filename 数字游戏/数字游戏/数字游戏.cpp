
//将数组vec所有元素排序，比如：1,2,5，6...
//前i-1个元素的和sum，初始值设为0，每次判断sum+1与第i个元素的大小关系
//（sum+1与vec[i]）,若sum+1<vec[i],说明sum与vec[i]之间出现了断裂，sum+1
//即为最小的断裂元素（不可能由前面的元素组合成）。
//比如当i=2时，sum=vec[0]+vec[1]=1+2=3,则0~3是可以连续取到的，而此时sum+1<5，
//即3~5之间出现了断裂，4是取不到的。

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//题目描述
//小易邀请你玩一个数字游戏，小易给你一系列的整数。
//你们俩使用这些整数玩游戏。每次小易会任意说一个数字出来，
//然后你需要从这一系列数字中选取一部分出来让它们的和等于小易所说的数字。
//例如： 如果{ 2,1,2,7 }是你有的一系列数，小易说的数字是11.
//你可以得到方案2 + 2 + 7 = 11.如果顽皮的小易想坑你，他说的数字是6
//那么你没有办法拼凑出和为6 现在小易给你n个数，
//让你找出无法从n个数中选取部分求和的数字中的最小数（从1开始）。

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> vec;
		for (int i = 0; i < n; i++)
		{
			int number;
			cin >> number;
			vec.push_back(number);
		}
		sort(vec.begin(), vec.end());
		long long sum = 0;
		int i;
		for (i = 0; i < n; i++)
		{
			if (sum + 1 < vec[i])
				break;
			sum += vec[i];
		}
		cout << sum + 1 << endl;
	}
}