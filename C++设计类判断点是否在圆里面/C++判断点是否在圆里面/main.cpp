#include<iostream>
#include "Point.h"
#include "Circle.h"

using namespace std;

int main()
{
	Circle c1;  //����Բ����
	Point p1;   //���������
	p1.setXY(0, 0);   //���õ�ĺ�������
	c1.setC(0, 0, 1);  //����Բ�ĺ������꼰�뾶
	if (c1.func(p1) == true)
	{
		cout << "����Բ��" << endl;

	}
	else
	{
		cout << "����Բ��" << endl;
	}
	system("pause");
	return 0;
}