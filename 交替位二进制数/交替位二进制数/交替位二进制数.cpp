//给定一个正整数，检查他是否为交替位二进制数：换句话说，就是他的二进制数相邻的两个位数永不相等。
//示例 1:
//输入: 5
//	输出 : True
//	解释 :
//	5的二进制数是 : 101
//		示例 2 :
//		输入 : 7
//		输出 : False
//		解释 :
//	7的二进制数是 : 111
//		示例 3 
//		输入 : 11
//		输出 : False
//		解释 :
//	11的二进制数是 : 1011
//		示例 4 :
//		输入 : 10
//		输出 : True
//		解释 :
//	10的二进制数是 : 1010

#include <iostream>
#include <vector>

using namespace std;

//第一步 先将这个数转换为二进制数并存到容器中
//第二步 比较容器中相邻两个数是否相等即可
bool hasAlternatingBits(int n) {
	if (n == 1) {
		return true;
	}
	vector<int>v;
	int tmp;
	while (n != 0) {
		tmp = n % 2;
		v.push_back(tmp);
		n /= 2;
	}
	int i = 0, j = 1;
	while (i < v.size() && j < v.size()) {
		if (v[i] == v[j]) {
			return false;
		}
		i++;
		j++;
	}
	return true;
}

int main(void) {

	cout << "输入一个数" << endl;
	int n;
	cin >> n;
	if (hasAlternatingBits(n)) {
		cout << "这个数是一个二进制位交替数" << endl;
	}
	else {
		cout << "这个数不是一个二进制位交替数" << endl;
	}
	system("pause");
	return 0;
}