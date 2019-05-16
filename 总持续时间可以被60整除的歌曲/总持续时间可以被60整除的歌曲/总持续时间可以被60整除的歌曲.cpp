//在歌曲列表中，第 i 首歌曲的持续时间为 time[i] 秒。
//返回其总持续时间（以秒为单位）可被 60 整除的歌曲对的数量。形式上，我们希望索引的数字  i < j 且有(time[i] + time[j]) % 60 == 0。
//	示例 1：
//	输入：[30, 20, 150, 100, 40]
//	输出：3
//	解释：这三对的总持续时间可被 60 整数：
//	(time[0] = 30, time[2] = 150) : 总持续时间 180
//	(time[1] = 20, time[3] = 100) : 总持续时间 120
//	(time[1] = 20, time[4] = 40) : 总持续时间 60
//	示例 2：
//
//	输入：[60, 60, 60]
//	输出：3
//	解释：所有三对的总持续时间都是 120，可以被 60 整数。

#include <iostream>
#include <vector>
using namespace std;


//其实给一个简洁的解释把：如果一个数对60的余数为20，则与它配对的数对60的余数必然为40。故只需查看余数为40的数的个数，
//即为配对数目，同时记录余数为20的数的数目。最后统计配对数目总和即可

int numPairsDivisibleBy60(vector<int>& time) {
	int map[60] = { 0 };
	int sum = 0;
	int i = 0;
	for (i = 0; i < time.size(); i++) {
		sum += map[(60 - time[i] % 60) % 60];
		map[time[i] % 60]++;
	}
	return sum;
}

int main(void) {
	
	cout << "请输入歌曲数目" << endl;
	int n;
	cin >> n;

	vector<int> v;
	int num = 0;
	for (int i = 0; i < n; i++) {
		cout << "请输入歌曲" << i + 1 << "的时间" << endl;
		cin >> num;
		v.push_back(num);
	}

	cout << numPairsDivisibleBy60(v) << endl;

	system("pause");
	return 0;
}