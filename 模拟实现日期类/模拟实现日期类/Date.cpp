#include "Date.h"

bool Date::operator>(const Date& d) const {
	if (this->_year > d._year) {
		return true;
	}
	if (this->_year == d._year) {
		if (this->_month > d._month) {
			return true;
		}
		if (this->_month == d._month) {
			if (this->_day > d._day) {
				return true;
			}
		}
	}
	return false;
}
bool Date::operator>=(const Date& d)const {
	if (*this > d || *this == d) {
		return true;
	}
	return false;
}
bool Date::operator<(const Date& d) const {
	if (*this >= d) {
		return false;
	}
	return true;
}
bool Date::operator<=(const Date& d)const {
	if (*this > d) {
		return false;
	}
	return true;
}
bool Date::operator==(const Date& d)const {
	if (this->_year == d._year && this->_month == d._month && this->_day == d._day) {
		return true;
	}
	return false;
}
bool Date::operator!=(const Date& d)const {
	if (*this == d) {
		return false;
	}
	return true;
}
//前置++
Date& Date::operator++() {
	return *this += 1;
} 
//后置++
Date Date::operator++(int) {
	Date ret(*this);
	*this += 1;
	return ret;
} 

//前置--
Date& Date::operator--() {
	return *this -= 1;
}
//后置--
Date Date::operator--(int) {
	Date ret = *this;
	*this -= 1;
	return ret;
}

Date Date::operator+(int day) const {
	Date ret = *this;
	ret += day;
	return ret;
}
Date Date::operator-(int day){
	Date ret = *this;
	ret -= day;
	return ret;
}

Date& Date::operator+=(int day) {

	if (day < 0) {
		return *this -= day;
	}

	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}
Date& Date::operator-=(int day) {

	_day -= day;
	while (_day <= 0) {
		_month--;
		if (_month == 0) {
			--_year;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}

int Date::operator-(const Date &d) {
	int day = 1;
	Date ret;
	while (true){
		ret = d + day;
		if (ret == *this) {
			break;
		}
		day++;
	}
	return day;
}