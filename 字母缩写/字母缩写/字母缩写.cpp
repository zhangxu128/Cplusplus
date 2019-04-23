#include<iostream>
#include<string>

//输入包括一个字符串s, 字符串长度length(1 ≤ length ≤ 50), 字符串中只包括小写字母('a'~'z')和空格。
//输出描述 :
//输出一个字符串, 即缩写的结果。
//示例1
//输入
//looks good to me
//输出
//lgtm


using namespace std;
int main()
{
	//string str;
	//while (cin >> str)
	//{
	//	cout << str[0];
	//}


	string str;
	while (cin >> str) {
		bool show = true;
		for (int i = 0; i < str.size(); ++i) {
			if (' ' == str[i]) {
				show = true;
			}
			else {
				if (show) {
					cout << str[i];
					show = false;
				}
			}
		}
		// cout << endl;
	}

	return 0;
}