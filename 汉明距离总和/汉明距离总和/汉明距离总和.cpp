//两个整数的 汉明距离 指的是这两个数字的二进制数对应位不同的数量。
//计算一个数组中，任意两个数之间汉明距离的总和。
//示例 :
//输入: 4, 14, 2
//	输出 : 6
//	解释 : 在二进制表示中，4表示为0100，14表示为1110，2表示为0010。（这样表示是为了体现后四位之间关系）
//	所以答案为：
//	HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.

#include <iostream>
#include <vector>

using namespace std;


//思路一：双层循环  遍历  记录不同位，但使用超时
//        取出每个数的每位比较记录     
int totalHammingDistance(vector<int>& nums) {
	int dist = 0;
	for (int i = 0; i < 8 * sizeof(int); i++) {
		int b1 = 0;
		for (int n : nums) {
			b1 += n >> i & 1;
		}
		dist += b1 * (nums.size() - b1);
	}
	return dist;
}

int main(void) {

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cout << totalHammingDistance(v) << endl;
	system("pause");
	return 0;
}