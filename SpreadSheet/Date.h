#pragma once
class Date {
private:
	int day;
	int month; 
	int year;
public:
	Date();
	Date(int, int, int);
	~Date();
	bool operator== (Date&);

};
