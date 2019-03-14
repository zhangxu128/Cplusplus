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
		//�ڶ��Ͽ������鳤��Ϊlen�������ռ�
		this->space = new int[this->len];

		cout << "������������вι��캯��" << endl;
	}
}

//�������캯��
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
	cout << "�������캯��������" << endl;
}


//��������
myArray::~myArray()
{
	if (this->space != NULL)
	{
		//��ʱspace�пռ䣬Ҫ�����ͷ�
		delete[] this->space;
		this->len = 0;
		this->space = NULL;
		cout << "��������������" << endl;
	}
}

//������Ԫ�ؽ��и�ֵ
void myArray::setData(int index, int data)
{
	if (this->space != NULL)
	{
		this->space[index] = data;
	}
}

//��ȡ����Ԫ��

int myArray::getData(int index)
{
	if (this->space != NULL)
	{
		return this->space[index];
	}
	return NULL;
}

//��ȡ���鳤��

int myArray::getLen()
{
	return this->len;
}