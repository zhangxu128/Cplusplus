//编写一个算法来判断一个数是不是“快乐数”。
//
//一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到 1。如果可以变为 1，那么这个数就是快乐数。
//
//示例 :
//
//输入: 19
//	输出 : true
//	解释 :
//	12 + 92 = 82
//	82 + 22 = 68
//	62 + 82 = 100
//	12 + 02 + 02 = 1


#include <iostream>

using namespace std;


//不是快乐数的数称为不快乐数（unhappy number），所有不快乐数的数位平方和计算
//最後都会进入 4 → 16 → 37 → 58 → 89 → 145 → 42 → 20 → 4 的循环中。
bool isHappy(int n) {
	int sum = 0;
	while (true) {
		while (n) {
			int m = n % 10;
			sum += m * m;
			n /= 10;
		}
		if (sum == 4 || sum == 20) return false;
		else if (sum == 1) return true;
		else {
			n = sum;
			sum = 0;
		}
	}
}

int main(void) {
	
	cout << "请输入一个数:";
	int n;
	cin >> n;
	if (isHappy(n)) {
		cout << "这个数是快乐数" << endl;
	}
	else {
		cout << "这个数不是快乐数" << endl;
	}

	system("pause");
	return 0;
}