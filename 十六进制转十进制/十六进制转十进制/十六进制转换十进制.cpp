//题目描述
//写出一个程序，接受一个十六进制的数值字符串，输出该数值的十进制字符串。（多组同时输入 ）
//输入描述 :
//输入一个十六进制的数值字符串。
//输出描述 :
//输出该数值的十进制字符串。
//示例1
//输入
//0xA
//输出
//10

#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;

	while (getline(cin, str)) {
		long num = 0; int index = 16;
		for (int i = 2; i < str.size(); ++i) {
			if (str[i] >= '0' && str[i] <= '9')
				num = num * 16 + (str[i] - '0');
			else
				num = num * 16 + (str[i] - 'A' + 10);
		}
		cout << num << endl;
	}
	system("pause");
	return 0;
}