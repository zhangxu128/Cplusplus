#include<iostream>
#include "Point.h"
#include "Circle.h"

using namespace std;

int main()
{
	Circle c1;  //创建圆对象
	Point p1;   //创建点对象
	p1.setXY(0, 0);   //设置点的横纵坐标
	c1.setC(0, 0, 1);  //设置圆的横纵坐标及半径
	if (c1.func(p1) == true)
	{
		cout << "点在圆上" << endl;

	}
	else
	{
		cout << "点在圆外" << endl;
	}
	system("pause");
	return 0;
}