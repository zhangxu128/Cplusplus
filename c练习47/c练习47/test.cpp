#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;


const double pi = 3.14;

//设计一个圆类，并计算其周长
class Circle 
{
  public:
	//成员属性,半径
	int r;
	//成员方法，进行设定半径的大小
	void setR(int c_r)
	{
		r = c_r;
	}
	//成员方法，进行计算圆的周长
	double c()
	{
		return 2 * pi * r;
	}
};


void test()
{
	Circle c1;
	c1.setR(10);
	cout << c1.c() << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}