#include "myArray.h"



myArray::myArray()
{
	this->len = 0;
	this->space = NULL;
}

myArray::myArray(int len)
{
	if (len <= 0)
	{
		this->len = 0;
		return;
	}
	else
	{
		this->len = len;
		//在堆上开辟数组长度为len的连续空间
		this->space = new int[this->len];

		cout << "调用了数组的有参构造函数" << endl;
	}
}

//拷贝构造函数
myArray::myArray(const myArray & another)
{
	if (another.len >= 0)
	{
		this->len = another.len;
		this->space = new int[this->len];
		for (int i = 0; i < this->len; i++)
		{
			this->space[i] = another.space[i];
		}
	}
	cout << "拷贝构造函数被调用" << endl;
}


//析构函数
myArray::~myArray()
{
	if (this->space != NULL)
	{
		//此时space有空间，要进行释放
		delete[] this->space;
		this->len = 0;
		this->space = NULL;
		cout << "调用了析构函数" << endl;
	}
}

//对数组元素进行赋值
void myArray::setData(int index, int data)
{
	if (this->space != NULL)
	{
		this->space[index] = data;
	}
}

//获取数组元素

int myArray::getData(int index)
{
	if (this->space != NULL)
	{
		return this->space[index];
	}
	return NULL;
}

//获取数组长度

int myArray::getLen()
{
	return this->len;
}