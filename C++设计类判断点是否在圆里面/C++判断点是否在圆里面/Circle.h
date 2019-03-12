#pragma once
#include "Point.h"
class Circle   //创建一个圆的类
{
public:   
	void setC(int x, int y, int r);
	bool func( Point &p);   //判断点是否在圆内（包括圆上）
private:
	int x0;   
	int y0;
	int m_r;
};

