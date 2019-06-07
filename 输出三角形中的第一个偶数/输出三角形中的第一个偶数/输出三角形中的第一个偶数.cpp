// 例
//        1
//      1 1 1
//    1 2 3 2 1
//  1 3 6 6 6 3 1

//  按照此规律输出第n行中的第一个偶数


#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n = 0;
	while (cin >> n) {
		if (n == 1 || n == 2) {
			cout << 0 << endl;
			continue;
		}
		vector<int>ret;
		vector<int>temp{ 1, 1, 1 };
		int sum = 0;
		for (int j = 2; j < n; j++) {
			ret.push_back(1);
			for (int i = 0; i < temp.size(); i++) {
				if (i == 0) {
					sum = temp[0] + temp[1];
					ret.push_back(sum);
					sum = 0;
				}
				else if (i == temp.size() - 1) {
					sum = temp[temp.size() - 1] + temp[temp.size() - 2];
					ret.push_back(sum);
					sum = 0;
				}
				else {
					sum = temp[i - 1] + temp[i] + temp[i + 1];
					ret.push_back(sum);
					sum = 0;
				}
			}
			ret.push_back(1);
			temp = ret;
			ret.clear();
		}
		//找到第一个偶数
		for (int i = 0; i < temp.size(); i++) {
			if (temp[i] % 2 == 0) {
				cout << i + 1 << endl;
				break;
			}
		}
	}
	return 0;
}
