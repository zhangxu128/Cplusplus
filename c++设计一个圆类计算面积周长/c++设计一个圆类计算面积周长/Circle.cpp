#include "Circle.h"

//����Բ�İ뾶
void Circle::setR(int c_r)
{
	r = c_r;
}

//����Բ�����
double Circle::getS()
{
	return r * r*3.14;
}

//����Բ���ܳ�
double Circle::getC()
{
	return 2 * r * 3.14;
}
