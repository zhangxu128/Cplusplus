#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;


const double pi = 3.14;

//���һ��Բ�࣬���������ܳ�
class Circle 
{
  public:
	//��Ա����,�뾶
	int r;
	//��Ա�����������趨�뾶�Ĵ�С
	void setR(int c_r)
	{
		r = c_r;
	}
	//��Ա���������м���Բ���ܳ�
	double c()
	{
		return 2 * pi * r;
	}
};


void test()
{
	Circle c1;
	c1.setR(10);
	cout << c1.c() << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}