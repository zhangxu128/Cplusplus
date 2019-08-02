//题目描述
//输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
//例如输入数组{ 3，32，321 }，
//则打印出这三个数字能排成的最小数字为321323。

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool MyCompare(const string &str1, const string &str2) {
	return str1 + str2 < str2 + str1;
}

string PrintMinNumber(vector<int> numbers) {
	string ret;   //接受返回值
	vector<string> numbers_str;
	for (int i = 0; i < numbers.size(); ++i) {
		//将容器中的数字转成字符串放入新容器中
		numbers_str.push_back(to_string(numbers[i]));
	}
	//进行自定义排序
	sort(numbers_str.begin(), numbers_str.end(), MyCompare);
	for (int i = 0; i < numbers_str.size(); ++i) {
		//直接相加就是最小的字符串数字
		ret += numbers_str[i];
	}
	return ret;
}

int main(void) {

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cout << PrintMinNumber(v) << endl;
	system("pause");
	return 0;
}