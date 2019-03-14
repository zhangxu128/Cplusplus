#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>

using namespace std;

class myArray
{
public:
	//无参构造
	myArray();

	myArray(int len);

	//拷贝构造函数
	myArray(const myArray& another);

	//获取数组元素
	int getData(int index);

	//对数组元素进行赋值
	void setData(int index, int data);

	//获取数组长度
	int getLen();

	//析构函数
	~myArray();
private:
	int len;  //数组长度
	int* space;//space是数组在堆上开辟空间的首地址
};

