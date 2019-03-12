#include "Circle.h"


//设置圆的横纵坐标及半径
void Circle::setC(int x,int y,int r)
{
	x0 = x;
	y0 = y;
	m_r = r;
}

//判断点是否在圆上
bool Circle::func(Point &p)
{
	int len = (p.getX() - x0)*(p.getX() - x0) + (p.getY() - y0)*(p.getY() - y0);
	if (len >= m_r*m_r)
	{
		return false;  //不在圆上返回false
	}
	return true;// 在圆上返回true
}
