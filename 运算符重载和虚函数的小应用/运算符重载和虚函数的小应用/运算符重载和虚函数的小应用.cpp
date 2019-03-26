#include<iostream>

using namespace std;

//运算符重载和虚函数
//内容提要
//使用虚函数编写程序求球体和圆柱体的体积及表面积。由于球体和圆柱体都可以看作由圆继承而来，
//所以可以定义圆类Circle作为基类。在Circle类中定义一个数据成员radius和两个虚函数area()和volume()。
//由Circle类派生Sphere类和Column类。在派生类中对虚函数area()和volume()重新定义
//分别求球体和圆柱体的体积及表面积。
//基本要求
//重载相应的运算符并编写程序，能运用虚函数编写程序测试并提交程序。

const double PI = 3.14;

class Circle   //基类
{
public:

	int radius;
	virtual double area() = 0;
	virtual double volume() = 0;
};


class Sphere : public Circle
{
public:
	Sphere(int r)
	{
		this->radius = r;
	}
	virtual double area()   //求圆的面积
	{
		return (4 * PI*this->radius*this->radius);
	}
	virtual double volume()   //求圆的体积
	{
		return (4 / 3 * PI*this->radius*this->radius*this->radius);
	}
};

class Colume : public Circle
{
public:
	Colume(int r,int h)
	{
		this->radius = r;
		this->height = h;
	}
	double getDC()  //求圆柱体底面周长
	{
		return 2 * PI*this->radius;
	}
	double getCS()  //求圆柱体侧面积
	{
		return	this->getDC()*this->height;
	}
	double getDS()  //求圆柱体底面积
	{
		return this->radius*this->radius*PI;
	}
	virtual double area()  //求圆柱体面积
	{
		return (this->getCS()+this->getDS()*2);
	}
	virtual double volume()  //求圆柱体体积
	{
		return this->getDS() * this->height;
	}
	double height;
};
int main(void)
{
	Circle * c1 = new Sphere(10);
	cout << "圆的面积为：" << c1->area() << endl;
	cout << "圆的体积为：" << c1->volume() << endl;
	Circle * c2 = new Colume(10,10);
	cout << "圆柱体的面积为：" << c2->area() << endl;
	cout << "圆柱体的体积为：" << c2->volume() << endl;
	system("pause");
	return 0;
}