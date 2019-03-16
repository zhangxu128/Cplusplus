#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "myString.h"
using namespace std;

int main()
{
	myString str1(10);
	cout << str1.getLen() << endl;;
	myString str2("abcd");
	cout << str1 << endl;
	cout << str2 << endl;
	myString str3 = str2;
	cout << str3 << endl;
	cout << str2.operator==(str3) << endl;
	myString str4 = "abcde";
	cout << str4.operator>(str3) << endl;
	char ch = 'c';
	str4.operator[](1) = ch;
	cout << str4 << endl;
	system("pause");
	return 0;
}