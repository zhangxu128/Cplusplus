#include "Circle.h"


//����Բ�ĺ������꼰�뾶
void Circle::setC(int x,int y,int r)
{
	x0 = x;
	y0 = y;
	m_r = r;
}

//�жϵ��Ƿ���Բ��
bool Circle::func(Point &p)
{
	int len = (p.getX() - x0)*(p.getX() - x0) + (p.getY() - y0)*(p.getY() - y0);
	if (len >= m_r*m_r)
	{
		return false;  //����Բ�Ϸ���false
	}
	return true;// ��Բ�Ϸ���true
}
