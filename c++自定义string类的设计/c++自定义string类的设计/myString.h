#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
using namespace std;

class myString
{
public:
	myString(); //无参构造函数

	myString(int len);//开辟len长度的字符串，全部设置为0

	myString(const char* str);//根据str字符串初始化myString

	myString(const myString &another);//拷贝构造函数

	myString & operator=(const myString &another);//重载=操作符

	char& operator[](int index);//重载[]操作符

	bool operator==(const myString &another);//重载==操作符

	bool operator!=(const myString &another);//重载!=操作符

	bool operator>(const myString &another);//重载>操作符

	bool operator<(const myString &another);//重载<操作符

	friend ostream & operator<<(ostream &os, myString &s);//重载<<左移操作符

	friend istream & operator>>(istream &is, myString &s);//重载>>左移操作符

	int getLen();//返回字符串的长度

	~myString();  //析构函数

private:
	int len;//  当前字符串的总长度
	char* str;//指向在堆上开辟内存的字符串的首地址
};

