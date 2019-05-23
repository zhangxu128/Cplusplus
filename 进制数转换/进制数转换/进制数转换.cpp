//将十进制数M 转换为 N进制 2<=N<=16
//当N大于9时,要用16进制的方式表示


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(void) {

	int M, N;
	cin >> M >> N;
	char num[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	vector<char> v;
	if (M == 0) {
		cout << num[0];
	}
	bool flag = false;
	if (M < 0) {
		flag = true;
		M = abs(M);
	}
	while (M != 0) {
		int tmp = M % N;
		v.push_back(num[tmp]);
		M /= N;
	}
	reverse(v.begin(), v.end());
	if (flag) {
		cout << '-';
		for (int i = 0; i < v.size(); i++) {
			cout << v[i];
		}
	}
	else {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i];
		}
	}

	cout << endl;
	system("pause");
	return 0;
}