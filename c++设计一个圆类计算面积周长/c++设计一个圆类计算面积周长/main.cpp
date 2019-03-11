#include<iostream>
#include "Circle.h"

using namespace std;

int main()
{
	Circle c1;   //创建一个圆的实例化对象
	c1.setR(10);   //设置半径
	cout << "c1的面积是：" << c1.getS() << endl;
	cout << "c1的周长是：" << c1.getC() << endl;
	system("pause");
	return 0;
}