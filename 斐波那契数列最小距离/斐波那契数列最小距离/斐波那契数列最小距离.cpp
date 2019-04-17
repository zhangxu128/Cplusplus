#include<iostream>
using namespace std;

//输入为一个正整数N(1 ≤ N ≤ 1, 000, 000)
//输出描述:
//输出一个最小的步数变为Fibonacci数"
//示例1
//输入
//15
//输出
//2


//求斐波那契数列值
int fib(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1 || n == 2) {
		return 1;
	}
	return fib(n - 1) + fib(n - 2);
}

//返回最小距离
int min(int a, int b) {
	return a = a <= b ? a : b;
}

int main(void) {
	int N;
	cin >> N;
	int ret = 0;
	for (int i = 0; i <= N; i++) {   // 计算最小距离
		if (fib(i) <= N && fib(i + 1) > N) {
			ret = min((N - fib(i)), (fib(i + 1) - N));
			break;
		}
	}
	cout << ret << endl;
	return 0;
}