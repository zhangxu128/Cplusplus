#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

using namespace std;

//实验四 继承性和派生类
//内容提要
//建立一个楼房基类Building为基类，用于存储地址和楼号，建立住宅类House继承Building，
//用来存储房号和面积，另外建立办公室类Office继承Building，存储办公室名称和电话号码。
//基本要求
//编制应用程序，建立住宅和办公室对象测试之并输出有关数据提交程序。


//楼房类
class Building
{
public:
	Building(int num,string addre)
	{
		this->num = num;
		this->addres = addre;
	}

	int num;//楼号
	string addres;//地址
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
		//cout << "建筑坐落与草滩名为" << this->addres << endl;
		cout << this->num << "号楼" << endl;
		cout << "房号为" << this->houseNum << endl;
		cout <<"面积为" << this->s << endl;
	}
	int houseNum;//房号
	int s;//面积
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
	Building building(4,"沁园小区");
	House house(101, 120,4,"沁园小区");
	//house.print();
	system("pause");
	return 0;
}