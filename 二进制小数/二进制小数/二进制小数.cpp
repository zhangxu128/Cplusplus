//题目描述
//有一个介于0和1之间的实数，类型为double，返回它的二进制表示。如果该数字无法精确地用32位以内的二进制表示，返回“Error”。
//给定一个double num，表示0到1的实数，请返回一个string，代表该数的二进制表示或者“Error”。
//测试样例：
//0.625
//返回：0.101


#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string printBin(double num) {
	stringstream res;
	res << "0.";
	for (int i = 0; i < 32; ++i) {
		if (num == 0.0) break;
		num *= 2;
		res << (int)num;
		num -= (int)num;
	}
	if (num == 0.0) {
		return res.str();
	}
	else {
		return "Error";
	}
}

int main(void) {

	double e;
	cin >> e;

	cout << printBin(e) << endl;
	system("pause");
	return 0;
}