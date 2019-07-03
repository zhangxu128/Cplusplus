//题目描述
//小M突然对怪数产生了兴趣。假设一个数n，如果[n / 1] + [n / 2] + ... + [n / k]
//(k为趋近于正无穷的正整数)为一个偶数，那么这个数是一个怪数，现在给定一个区间[a, b]，求[a, b]之间有多少怪数。
//[x]表示不大于x的最大整数。
//输入描述 :
//输入只包含一行，有两个非负整数a, b(0 <= a, b <= 2 ^ 31, a <= b)。
//输出描述 :
//输出区间[a, b]中的怪数的个数。
//示例1
//输入
//0 10
//输出
//6

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
	long isStrange(long num) {
		return (long(floor(sqrt(num))) & 1) == 0 ? 1 : 0;
	}

	// strange number from 0 to n
	long StrangeNumber(long &n) {
		long res = 0;
		long last = long(floor(sqrt(n)));
		if (last & 1) {
			res = last * (last + 1) >> 1;
		}
		else {
			res = last * (last - 1) >> 1;
			res += (n - last * last + 1);
		}
		return res;
	}
};

int main() {
	long a, b;
	cin >> a >> b;
	Solution s;
	long ret = s.StrangeNumber(b) - s.StrangeNumber(a) + s.isStrange(a);
	printf("%d", ret);
	system("pause");
	return 0;
}