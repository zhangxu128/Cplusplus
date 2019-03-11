#pragma once
class Circle  //创建一个圆类
{
public:
	void setR(int c_r);  
	double getS();   //获取圆的面积
	double getC();  //获取圆的周长
private:
	int r;    //圆的半径
	double s;//圆的面积
	double c;//圆的周长
};

