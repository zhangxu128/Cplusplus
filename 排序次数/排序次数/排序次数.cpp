#include <iostream>
#include <vector>
using namespace std;

//题目描述
//小摩有一个N个数的数组，他想将数组从小到大 排好序，但是萌萌的小摩只会下面这个操作：
//任取数组中的一个数然后将它放置在数组的最后一个位置。
//问最少操作多少次可以使得数组从小到大有序？
//输入描述 :
//首先输入一个正整数N，接下来的一行输入N个整数。(N <= 50, 每个数的绝对值小于等于1000)
//输出描述 :
//	输出一行操作数
//	示例1
//	输入
//	4
//	19 7 8 25
//	输出
//	2


int main(void) {

	int N;
	cin >> N;
	//计数
	int count = 0;
	vector <int> v;
	int number;
	for (int i = 0; i < N; i++) {
		cin >> number;
	}
	for (int i = 0; i < v.size() - 1; i++) {
		if (v[i] > v[i + 1]) {
			count++;
			v.push_back(v[i]);
		}
	}
	cout << count << endl;
	system("pause");
	return 0;
}
