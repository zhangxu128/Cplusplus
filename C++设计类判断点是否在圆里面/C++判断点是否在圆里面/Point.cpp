#include "Point.h"


//设置点的横纵坐标
void Point::setXY(int x,int y)
{
	px = x;
	py = y;
}

//获取点的横坐标
int Point::getX()
{
	return px;
}

//获取点的纵坐标
int Point::getY()
{
	return py;
}