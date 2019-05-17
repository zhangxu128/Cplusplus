#pragma once

#include <iostream>

using std::cout;
using std::endl;

//定义一个日期类
class Date
{
public:
	//获取这个月有多少天
	int GetMonthDay(int year, int month) const {
		static int MonthDay[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if ((month == 2) &&
			(year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
			
			return 29;
		}
		return MonthDay[month];
	}

	Date(int year = 1900,int month = 1,int day = 1) {
		if (year >= 1900 && month > 0 && month < 13 && day>0 && day <= GetMonthDay(year, month)) {
			_year = year;
			_month = month;
			_day = day;
		}
		else {
			cout << "日期非法" << endl;
		}
	}
	void print() {
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	bool operator>(const Date& d) const;
	bool operator>=(const Date& d)const;
	bool operator<(const Date& d) const;
	bool operator<=(const Date& d)const;
	bool operator==(const Date& d)const;
	bool operator!=(const Date& d)const;

	Date& operator++();  //前置++
	Date operator++(int); //后置++

	Date& operator--(); //前置--
	Date operator--(int); //后置--
	
	Date operator+(int day) const;
	Date operator-(int day);

	Date& operator+=(int day);
	Date& operator-=(int day);

	int operator-(const Date&d);
private:
	int _year;
	int _month;
	int _day;
};

