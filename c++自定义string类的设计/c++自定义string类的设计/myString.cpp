#include "myString.h"


using namespace std;

myString::myString()
{
	this->len = 0;
	this->str = NULL;
}


myString::~myString()
{
	if(this->str!=NULL)
	{
		delete[] this->str;
		this->len = 0;
		this->str = NULL;
	}
	cout << "ִ������������" << endl;
}

myString::myString(int len)//����len���ȵ��ַ�����ȫ������Ϊ0
{
	if (len == 0)
	{
		this->len = 0;
		this->str = new char[len + 1];
		strcpy(this->str, "");
	}
	else
	{
		this->len = len;
		this->str = new char[this->len + 1];
		memset(this->str, 0, this->len + 1);
	}

}

myString::myString(const myString &another)//�������캯��
{
	this->len = another.len;
	this->str = new char[this->len + 1];
	strcpy(this->str, another.str);
}

myString::myString(const char* str)//����str�ַ�����ʼ��myString
{
	if (str == NULL)
	{
		this->len = 0;
		this->str = new char[len + 1];
		strcpy(this->str, "");
	}
	else
	{
		int len = strlen(str);
		this->len = len;
		this->str = new char[this->len + 1];
		strcpy(this->str, str);
	}
}

myString & myString::operator=(const myString &another)//����=������
{
	//���ͷ�ԭ�е��ڴ�ռ�
	if (this->str != NULL)
	{
		delete[] this->str;
		this->len = 0;
		this->str = NULL;
	}
	else
	{
		this->len = another.len;
		this->str = new char[this->len + 1];
		strcpy(this->str, another.str);
	}
	return *this;
}

char& myString::operator[](int index)//����[]������
{
	return this->str[index];
}

bool myString::operator==(const myString &another)//����==������
{
	if (strcmp(this->str, another.str) == 0)
	{
		return true;
	}
	return false;
}

bool myString::operator!=(const myString &another)//����!=������
{
	if (strcmp(this->str, another.str) == 0)
	{
		return false;
	}
	return true;
	
	//return !(*this==another)
}

bool myString::operator>(const myString &another)//����>������
{
	int ret = strcmp(this->str, another.str);
	if (ret > 0)
	{
		return true;
	}
	return false;
}

bool myString::operator<(const myString &another)//����<������
{
	return !(*this > another);
}

ostream& operator<<(ostream &os, myString &s)//����<<���Ʋ�����
{
	os << s.str;
	return os;
}

istream & operator>>(istream &is, myString &s)//����>>���Ʋ�����
{
	char buf[1024] = { 0 };
	char* tmp = buf;
	cout << "������һ���ַ���:";
	cin >> tmp;
	int len = strlen(buf);
	s.str = new char[len + 1];
	strcpy(s.str, buf);
	s.len = len;
	return is;
}

int myString::getLen()//�����ַ����ĳ���
{
	return this->len;
}

