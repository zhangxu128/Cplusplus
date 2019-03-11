#include "Circle.h"

//设置圆的半径
void Circle::setR(int c_r)
{
	r = c_r;
}

//计算圆的面积
double Circle::getS()
{
	return r * r*3.14;
}

//计算圆的周长
double Circle::getC()
{
	return 2 * r * 3.14;
}
