#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//简易版String类实现
class String {
public:
	String(const char* str=nullptr) {
		if (str == nullptr) {
			_str = new char[1];
			*_str = '\0';
		}
		else {
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
	}

	String(const String& s) {
		_str = new char[strlen(s._str) + 1];
		strcpy(_str, s._str);
	}

	String& operator=(const String& s) {
		
		if (this == &s) {
			return *this;
		}
		delete[] _str;
		_str = new char[strlen(s._str) + 1];
		strcpy(_str, s._str);
		return *this;
	}

	~String() {
		if (_str != nullptr) {
			delete[] _str;
			_str = nullptr;
		}
	}

	friend ostream& operator<<(ostream &os, String &str) {
		os << str._str;
		return os;
	}

private:
	char* _str;
};




int main(void) {

	String a("hello");
	String b("world");
	String c(a);
	c = b;
	cout << a << " " << b << " " << c << " "<< endl;
	system("pause");
	return 0;
}