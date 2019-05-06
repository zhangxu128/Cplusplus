#include <iostream>
#include <string>

using namespace std;


//报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：
//1.     1
//2.     11
//3.     21
//4.     1211
//5.     111221
//6.     312211
//  1 被读作  "one 1"  ("一个一"), 即 11。
//  11 被读作 "two 1s" ("两个一"）, 即 21。
//	21 被读作 "one 2", "one 1" （"一个二", "一个一"), 即 1211。
//	给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。
//	注意：整数顺序将表示为一个字符串。
//	示例 1:
//输入: 1
//	输出 : "1"
//	示例 2 :
//	输入 : 4
//	输出 : "1211"


string countAndSay(int n) {

	if (n == 1) {
		return "1";
	}
	if (n == 2) {
		return "11";
	}
	string begin = "11";
	while (n-2) {
		string end = "";
		int flag = 0;
		//cout << begin << endl;
		for (int i = 0; i < begin.length()-1; i++) {
			int num = 1;
			while (begin[i] == begin[i + 1]&&i<begin.length()) {
				if (i + 1 == begin.length() - 1) {
					flag = 1;
				}
				num++;
				i++;
			}
			//现在不相等，进行增加操作
			end = end +to_string(num) + begin[i];
		}
		if (flag == 0) {
			//将最后一个加上即可
			char c = begin[begin.length() - 1];
			end = end + "1" + c;
		}
		begin = end;
		n--;
	}
	return begin;
}
int main(void) {
	
	int n;
	cin >> n;
	cout<<countAndSay(n)<<endl;
	system("pause");
	return 0;
}