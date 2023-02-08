#include <iostream>
#include "Date.h"
Date::Date(){}
Date::Date(int d, int m, int y){
	if ((d > 0 && d <= 31) && (m > 0 && m <= 12) && (y >= 0 && d <= 2023)) {
		day = d;
		month = m;
		year = y;
	}
	else {
		std::cout << "invalid value"<<std::endl;
		return;
	}
}
Date::~Date() { /*std::cout << "Date Dtor" << std::endl; */ }
bool Date::operator== (Date& other) { 
	if ((this->day == other.day) && (this->month == other.month) && (this->year == other.year)) {
		return true;
	}
	else {
		return false;
	}
}