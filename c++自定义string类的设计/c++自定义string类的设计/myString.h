#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
using namespace std;

class myString
{
public:
	myString(); //�޲ι��캯��

	myString(int len);//����len���ȵ��ַ�����ȫ������Ϊ0

	myString(const char* str);//����str�ַ�����ʼ��myString

	myString(const myString &another);//�������캯��

	myString & operator=(const myString &another);//����=������

	char& operator[](int index);//����[]������

	bool operator==(const myString &another);//����==������

	bool operator!=(const myString &another);//����!=������

	bool operator>(const myString &another);//����>������

	bool operator<(const myString &another);//����<������

	friend ostream & operator<<(ostream &os, myString &s);//����<<���Ʋ�����

	friend istream & operator>>(istream &is, myString &s);//����>>���Ʋ�����

	int getLen();//�����ַ����ĳ���

	~myString();  //��������

private:
	int len;//  ��ǰ�ַ������ܳ���
	char* str;//ָ���ڶ��Ͽ����ڴ���ַ������׵�ַ
};

