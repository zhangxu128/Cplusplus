//给定范围[m, n]，其中 0 <= m <= n <= 2147483647，返回此范围内所有数字的按位与（包含 m, n 两端点）。
//示例 1:
//输入: [5, 7]
//	输出 : 4
//	示例 2 :
//	输入 : [0, 1]
//	输出 : 0

#include <iostream>

using namespace std;


//思路：
//n的二进制位比m二进制最左边的1高时，&的结果必然为0； 由这个思想启发，二进制最高位相同时，
//这个1会保存，然后比较右一位，相同也保留... 
//所以只需要m n 同时右移到相等时 m n的值就是&后能保留的位数，
//然后左移回来就是最后的值。
int rangeBitwiseAnd1(int m, int n) {
	if (m == 0 || n / 2 >= m)    return 0;//×2会溢出
	if (m == n)    return m;
	for (int i = n; i >= m; i--)//向下取不会溢出
		n = n & i;
	return n;
}

int rangeBitwiseAnd2(int m, int n) {
	int  count = 0;   // 101  10 100
					// 111  11 1
	while (m != n) {
		m >>= 1;
		n >>= 1;
		count++;
	}
	return m << count;
}

int main(void) {

	int m, n;
	cin >> m >> n;
	cout << rangeBitwiseAnd1(m, n) << endl;
	cout << rangeBitwiseAnd2(m, n) << endl;
	system("pause");
	return 0;
}