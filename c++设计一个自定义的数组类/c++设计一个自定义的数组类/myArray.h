#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>

using namespace std;

class myArray
{
public:
	//�޲ι���
	myArray();

	myArray(int len);

	//�������캯��
	myArray(const myArray& another);

	//��ȡ����Ԫ��
	int getData(int index);

	//������Ԫ�ؽ��и�ֵ
	void setData(int index, int data);

	//��ȡ���鳤��
	int getLen();

	//��������
	~myArray();
private:
	int len;  //���鳤��
	int* space;//space�������ڶ��Ͽ��ٿռ���׵�ַ
};

