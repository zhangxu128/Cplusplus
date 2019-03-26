#include<iostream>

using namespace std;

//��������غ��麯��
//������Ҫ
//ʹ���麯����д�����������Բ��������������������������Բ���嶼���Կ�����Բ�̳ж�����
//���Կ��Զ���Բ��Circle��Ϊ���ࡣ��Circle���ж���һ�����ݳ�Աradius�������麯��area()��volume()��
//��Circle������Sphere���Column�ࡣ���������ж��麯��area()��volume()���¶���
//�ֱ��������Բ�����������������
//����Ҫ��
//������Ӧ�����������д�����������麯����д������Բ��ύ����

const double PI = 3.14;

class Circle   //����
{
public:

	int radius;
	virtual double area() = 0;
	virtual double volume() = 0;
};


class Sphere : public Circle
{
public:
	Sphere(int r)
	{
		this->radius = r;
	}
	virtual double area()   //��Բ�����
	{
		return (4 * PI*this->radius*this->radius);
	}
	virtual double volume()   //��Բ�����
	{
		return (4 / 3 * PI*this->radius*this->radius*this->radius);
	}
};

class Colume : public Circle
{
public:
	Colume(int r,int h)
	{
		this->radius = r;
		this->height = h;
	}
	double getDC()  //��Բ��������ܳ�
	{
		return 2 * PI*this->radius;
	}
	double getCS()  //��Բ��������
	{
		return	this->getDC()*this->height;
	}
	double getDS()  //��Բ��������
	{
		return this->radius*this->radius*PI;
	}
	virtual double area()  //��Բ�������
	{
		return (this->getCS()+this->getDS()*2);
	}
	virtual double volume()  //��Բ�������
	{
		return this->getDS() * this->height;
	}
	double height;
};
int main(void)
{
	Circle * c1 = new Sphere(10);
	cout << "Բ�����Ϊ��" << c1->area() << endl;
	cout << "Բ�����Ϊ��" << c1->volume() << endl;
	Circle * c2 = new Colume(10,10);
	cout << "Բ��������Ϊ��" << c2->area() << endl;
	cout << "Բ��������Ϊ��" << c2->volume() << endl;
	system("pause");
	return 0;
}