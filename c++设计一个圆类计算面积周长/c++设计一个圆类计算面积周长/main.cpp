#include<iostream>
#include "Circle.h"

using namespace std;

int main()
{
	Circle c1;   //����һ��Բ��ʵ��������
	c1.setR(10);   //���ð뾶
	cout << "c1������ǣ�" << c1.getS() << endl;
	cout << "c1���ܳ��ǣ�" << c1.getC() << endl;
	system("pause");
	return 0;
}