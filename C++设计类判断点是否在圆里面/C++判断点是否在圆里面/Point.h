#pragma once
class Point   //创建一个点的类
{
public:   //生命
	void setXY(int x, int y);
	int getX();
	int getY();
private:
	int px;    //点的横坐标
	int py;   //点的纵坐标
};

