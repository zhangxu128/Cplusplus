#include<iostream>
using namespace std;

//请实现一个函数，将一个字符串中的每个空格替换成“ % 20”。
//例如，当字符串为We Are Happy.
//则经过替换之后的字符串为We % 20Are % 20Happy。

class Solution {
public:
	void replaceSpace(char *str, int length) {
		int count = 0;
		for (int i = 0; i < length; i++) {   //计算空格数
			if (str[i] == ' ')
				count++;
		}
		for (int i = length - 1; i >= 0; i--) {
			if (str[i] != ' ') {
				str[i + 2 * count] = str[i];   //移动位置
			}
			else {
				count--;
				str[i + 2 * count] = '%';		//字符替换
				str[i + 2 * count + 1] = '2';
				str[i + 2 * count + 2] = '0';
			}
		}
	}
};

int main()
{
	char str[] = "we are very  happy!";
	int len = strlen(str);
	Solution s;
	s.replaceSpace(str, len+1);
	cout << str << endl;
	system("pause");
	return 0;
}