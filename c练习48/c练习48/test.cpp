#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
//����һ��ѧ����
class student {
public:  //����Ȩ��
	string name;
	int age;
	void setage(int m_age)
	{
		age = m_age;
	}
	void setname(string names)
	{
		name = names;
	}
	void print()
	{
		cout << "ѧ��������" << name << " " << "ѧ������:" << age << endl;
	}
};


void test()
{
 //���ʵ����
	student s1;
	s1.age = 10;
	s1.name = "����";
	s1.print();
}

int main()
{
	test();
	system("pause");
	return 0;
}