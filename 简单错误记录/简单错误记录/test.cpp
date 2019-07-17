//题目
//开发一个简单错误记录功能小模块，能够记录出错的代码所在的文件名称和行号。
//处理：
//1、 记录最多8条错误记录，循环记录，对相同的错误记录（净文件名称和行号完全匹配）只记录一条，错误计数增加；
//2、 超过16个字符的文件名称，只记录文件的最后有效16个字符；
//3、 输入的文件可能带路径，记录文件名称不能带路径。
//输入描述 :
//一行或多行字符串。每行包括带路径文件名称，行号，以空格隔开。
//输出描述 :
//将所有的记录统计并将结果输出，格式：文件名 代码行数 数目，一个空格隔开，如：
//示例1
//输入
//E : \V1R2\product\fpgadrive.c   1325
//输出
//	fpgadrive.c 1325 1

//这题思路很简单，本质上就是把输入暂存起来，并记录不同输入的数量，如果遇到重复的就数量 + 1。
//关键是在实现上，由于输入字符串及其数量是绑定的，所以要用一个结构体来存储它们，
//以便在同时查找字符串的时候可以修改它的数量。这里直接把文件名和行号连接成一个字符串，
//不需要分成两个字符串来对比。用find函数查找自定义类型必须要重载“ == ”。
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct ErrMsg {
	string fname;
	int num;

	ErrMsg(string fname) {
		this->fname = fname;
		this->num = 1;
	}

	bool operator==(const ErrMsg & a) {
		return fname == a.fname;
	}
};
int main()
{
	string dirName, lineNum;
	vector<ErrMsg> v;
	while (cin >> dirName >> lineNum)
	{
		string fileName = dirName.substr(dirName.find_last_of("\\") + 1);
		if (fileName.size() > 16) fileName.erase(fileName.begin(), fileName.end() - 16);
		fileName = fileName + " " + lineNum;//把文件名和行号连接成一个字符串
		ErrMsg er(fileName);
		auto it = find(v.begin(), v.end(), er);
		if (it == v.end())
			v.push_back(er);
		else (*it).num++;
	}
	if (v.size() <= 8 && v.size() >= 0)
		for (auto e : v) cout << e.fname << " " << e.num << endl;
	else if (v.size() > 8)
		for (auto ite = v.end() - 8; ite < v.end(); ite++) cout << (*ite).fname << " " << (*ite).num << endl;
	system("pause");
	return 0;
}