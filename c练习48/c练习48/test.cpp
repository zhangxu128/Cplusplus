#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
//创建一个学生类
class student {
public:  //公共权限
	string name;
	int age;
	void setage(int m_age)
	{
		age = m_age;
	}
	void setname(string names)
	{
		name = names;
	}
	void print()
	{
		cout << "学生姓名：" << name << " " << "学生年龄:" << age << endl;
	}
};


void test()
{
 //类的实例化
	student s1;
	s1.age = 10;
	s1.name = "张旭";
	s1.print();
}

int main()
{
	test();
	system("pause");
	return 0;
}