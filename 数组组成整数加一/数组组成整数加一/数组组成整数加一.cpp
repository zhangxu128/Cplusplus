//给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
//
//最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。
//
//你可以假设除了整数 0 之外，这个整数不会以零开头。
//
//示例 1:
//
//输入: [1, 2, 3]
//	输出 : [1, 2, 4]
//	解释 : 输入数组表示数字 123。
//	示例 2 :
//
//	输入 : [4, 3, 2, 1]
//	输出 : [4, 3, 2, 2]
//	解释 : 输入数组表示数字 4321。

#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
	//分两种情况，没有9直接加一
	//有9改0，循环继续，直到不为9

	for (int i = digits.size() - 1; i >= 0; i--) {
		if (digits[i] < 9) {
			digits[i] += 1;
			return digits;
		}
		else {
			digits[i] = 0;
		}
	}
	vector<int> v;
	v.push_back(1);
	for (int i = 0; i < digits.size(); i++) {

		v.push_back(digits[i]);
	}
	return v;
}

int main(void) {
	
	cout << "请输入数组元素:";
	int n;
	cin >> n;
	vector<int> v;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	vector<int> ret = plusOne(v);
	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}