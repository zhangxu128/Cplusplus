#include<iostream>
#include<fstream>
using namespace std;

//�ļ�����
//������Ҫ
//1.ͨ���ļ����������д�����������֡�
//2.�ر��ļ����������Ȼ��۲�����ļ����ݡ�
//3.����open���������ļ����������ѡ���ʵ����ļ�������ʽ��
//4.��ԭ���ݵĺ���׷�������������ݡ�
//����Ҫ��
//�����������ļ����ֲ�����д������Բ��ύ����

void test1()
{
	string str = "D:\\vs2017\\workspace\\c++�ļ�С��ϰ\\c++�ļ�С��ϰ\\hello.txt";
	char str2[] = "hello world!";
	ofstream osm(str, ios::out);
	if (!osm)
	{
		cout << "�ļ�д��ʧ�ܣ�" << endl;;
	}
	for (int i = 0; str2[i] != '\0'; i++)
	{
		osm.put(str2[i]);
	}
	osm.close();
}
void test2()
{
	string str = "D:\\vs2017\\workspace\\c++�ļ�С��ϰ\\c++�ļ�С��ϰ\\hello.txt";
	char str2[] = "hello world! world hello!";
	ofstream osm1;
	osm1.open(str, ios::out | ios::app);
	if (!osm1)
	{
		cout << "�ļ�д��ʧ�ܣ�" << endl;;
	}
	for (int i = 0; str2[i] != '\0'; i++)
	{
		osm1.put(str2[i]);
	}
	osm1.close();
}
int main()
{
	//test1();
	test2();
	system("pause");
	return 0;
}