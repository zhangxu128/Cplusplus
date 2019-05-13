//给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c。
//示例1 :
//输入: 5
//	输出 : True
//	解释 : 1 * 1 + 2 * 2 = 5
//	示例2 :
//	输入 : 3
//	输出 : False

#include <iostream>

using namespace std;


//利用双指针 求解
bool judgeSquareSum(int c,int* ii,int* jj) {
	long i = 0, j = (int)sqrt(c), tmp;
	while (i <= j) {
		tmp = i * i + j * j - c;
		if (tmp == 0) {
			*ii = i;
			*jj = j;
			return true;
		}
		if (tmp > 0) j = j - 1;
		else i = i + 1;
	}
	return false;
}

int main(void){

	cout << "请输入一个数" << endl;
	int n;
	cin >> n;
	int i, j;
	if (judgeSquareSum(n, &i, &j)) {
		cout << i << "*" << i << "+" << j << "*" << j << "=" << n << endl;
	}
	else {
		cout << "该数无法由两个数的平方和构成" << endl;
	}
	system("pause");
	return 0;
}