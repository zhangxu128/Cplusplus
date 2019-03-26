#include<iostream>
#include<fstream>
using namespace std;

//文件操作
//内容提要
//1.通过文件输出流对象，写入若干行文字。
//2.关闭文件输出流对象，然后观察磁盘文件内容。
//3.改用open函数创建文件输出流，并选择适当的文件操作方式。
//4.在原内容的后面追加若干行新内容。
//基本要求
//能熟练运用文件各种操作编写程序测试并提交程序。

void test1()
{
	string str = "D:\\vs2017\\workspace\\c++文件小练习\\c++文件小练习\\hello.txt";
	char str2[] = "hello world!";
	ofstream osm(str, ios::out);
	if (!osm)
	{
		cout << "文件写入失败！" << endl;;
	}
	for (int i = 0; str2[i] != '\0'; i++)
	{
		osm.put(str2[i]);
	}
	osm.close();
}
void test2()
{
	string str = "D:\\vs2017\\workspace\\c++文件小练习\\c++文件小练习\\hello.txt";
	char str2[] = "hello world! world hello!";
	ofstream osm1;
	osm1.open(str, ios::out | ios::app);
	if (!osm1)
	{
		cout << "文件写入失败！" << endl;;
	}
	for (int i = 0; str2[i] != '\0'; i++)
	{
		osm1.put(str2[i]);
	}
	osm1.close();
}
int main()
{
	//test1();
	test2();
	system("pause");
	return 0;
}