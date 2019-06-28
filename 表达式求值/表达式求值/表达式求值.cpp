//题目描述
//今天上课，老师教了小易怎么计算加法和乘法，乘法的优先级大于加法，但是如果一个运算加了括号，那么它的优先级是最高的。例如：
//1 + 2 * 3 = 7
//1 * (2 + 3) = 5
//1 * 2 * 3 = 6
//(1 + 2) * 3 = 9
//现在小易希望你帮他计算给定3个数a，b，c，在它们中间添加"+"， "*"， "("， ")"符号，能够获得的最大值。
//输入描述 :
//一行三个数a，b，c(1 <= a, b, c <= 10)
//输出描述 :
//	能够获得的最大值
//	示例1
//	输入
//	1 2 3
//	输出
//	9

#include<iostream>
#include<vector>
using namespace std;
int max(int a, int b, int c) {
	vector<int> count;
	int max_n = 0;
	int max_1 = a + b + c;
	int max_2 = a * b + c;
	int max_3 = a * b*c;
	int max_4 = (a + b)*c;
	count.push_back(max_1);
	count.push_back(max_2);
	count.push_back(max_3);
	count.push_back(max_4);
	for (int i = 0; i < count.size(); i++) {
		if (count[i] > max_n) {
			max_n = count[i];
		}
	}
	return max_n;
}
int main() {
	int x, y, z;
	int max_num;
	while (cin >> x >> y >> z) {
		max_num = 0;
		int max_1 = max(x, y, z);
		int max_2 = max(y, z, x);
		max_num = max_1 > max_2 ? max_1 : max_2;
		cout << max_num << endl;
	}
	return 0;
}