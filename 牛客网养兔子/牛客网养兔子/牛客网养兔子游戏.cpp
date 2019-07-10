// write your code here cpp

//题目描述
//
//一只成熟的兔子每天能产下一胎兔子。每只小兔子的成熟期是一天。 
//某人领养了一只小兔子，请问第N天以后，他将会得到多少只兔子。
//输入描述 :
//测试数据包括多组，每组一行，为整数n(1≤n≤90)。
//输出描述 :
//对应输出第n天有几只兔子(假设没有兔子死亡现象)。


#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int n;
	while (cin >> n) {
		vector<long long>v(91);
		v[1] = 1;
		v[2] = 2;
		for (int i = 3; i < n + 1; i++) {
			v[i] = v[i - 1] + v[i - 2];
		}
		cout << v[n] << endl;
	}
	system("pause");
	return 0;
}