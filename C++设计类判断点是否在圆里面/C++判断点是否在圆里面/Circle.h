#pragma once
#include "Point.h"
class Circle   //����һ��Բ����
{
public:   
	void setC(int x, int y, int r);
	bool func( Point &p);   //�жϵ��Ƿ���Բ�ڣ�����Բ�ϣ�
private:
	int x0;   
	int y0;
	int m_r;
};

