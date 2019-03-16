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
	cout << "执行了析构函数" << endl;
}

myString::myString(int len)//开辟len长度的字符串，全部设置为0
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

myString::myString(const myString &another)//拷贝构造函数
{
	this->len = another.len;
	this->str = new char[this->len + 1];
	strcpy(this->str, another.str);
}

myString::myString(const char* str)//根据str字符串初始化myString
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

myString & myString::operator=(const myString &another)//重载=操作符
{
	//先释放原有的内存空间
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

char& myString::operator[](int index)//重载[]操作符
{
	return this->str[index];
}

bool myString::operator==(const myString &another)//重载==操作符
{
	if (strcmp(this->str, another.str) == 0)
	{
		return true;
	}
	return false;
}

bool myString::operator!=(const myString &another)//重载!=操作符
{
	if (strcmp(this->str, another.str) == 0)
	{
		return false;
	}
	return true;
	
	//return !(*this==another)
}

bool myString::operator>(const myString &another)//重载>操作符
{
	int ret = strcmp(this->str, another.str);
	if (ret > 0)
	{
		return true;
	}
	return false;
}

bool myString::operator<(const myString &another)//重载<操作符
{
	return !(*this > another);
}

ostream& operator<<(ostream &os, myString &s)//重载<<左移操作符
{
	os << s.str;
	return os;
}

istream & operator>>(istream &is, myString &s)//重载>>左移操作符
{
	char buf[1024] = { 0 };
	char* tmp = buf;
	cout << "请输入一个字符串:";
	cin >> tmp;
	int len = strlen(buf);
	s.str = new char[len + 1];
	strcpy(s.str, buf);
	s.len = len;
	return is;
}

int myString::getLen()//返回字符串的长度
{
	return this->len;
}

