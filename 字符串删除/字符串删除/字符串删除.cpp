//输入两个字符串，删除第一个字符串中第二个字符串的所有元素
//
//

#include <iostream>
#include <string>

using namespace std;

//思路：删除的话比较耗费代价，不易操作，所以还是重组方便
//      重组就要里利用hash映射，将字符串2中的元素映射到表中
//      遍历s1，表中为0的位置重组即可。。
int main() {

	string s1;
	string s2;
	getline(cin,s1);
	getline(cin, s2);

	char hashtable[256] = { 0 };
	//映射
	for (int i = 0; i < s2.size(); i++) {
		hashtable[s2[i]]++;
	}
	
	string s = "";
	//重组
	for (int i = 0; i < s1.size(); i++) {
		if (hashtable[s1[i]] == 0) {
			s += s1[i];
		}
	}
	cout << s << endl;
	system("pause");
	return 0;
}