#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

using namespace std;

//ʵ���� �̳��Ժ�������
//������Ҫ
//����һ��¥������BuildingΪ���࣬���ڴ洢��ַ��¥�ţ�����סլ��House�̳�Building��
//�����洢���ź���������⽨���칫����Office�̳�Building���洢�칫�����ƺ͵绰���롣
//����Ҫ��
//����Ӧ�ó��򣬽���סլ�Ͱ칫�Ҷ������֮������й������ύ����


//¥����
class Building
{
public:
	Building(int num,string addre)
	{
		this->num = num;
		this->addres = addre;
	}

	int num;//¥��
	string addres;//��ַ
};


class House : public Building
{
public:
	House(int h, int m_s,int num,string addre):Building(num,addres)
	{
		this->houseNum = h;
		this->s = m_s;
		//this->addres = addre;
		//this->num = num;
	}
	void print()
	{
		//cout << "�����������̲��Ϊ" << this->addres << endl;
		cout << this->num << "��¥" << endl;
		cout << "����Ϊ" << this->houseNum << endl;
		cout <<"���Ϊ" << this->s << endl;
	}
	int houseNum;//����
	int s;//���
};

class Office : public Building
{
public:
	Office(int pnum,char* office,int num,string addres):Building(num,addres)
	{
		this->phoneNum = pnum;
		this->officeName = office;
		this->num = num;
		this->addres = addres;
	}
	int phoneNum;
	string officeName;
};


int main()
{
	Building building(4,"��԰С��");
	House house(101, 120,4,"��԰С��");
	//house.print();
	system("pause");
	return 0;
}