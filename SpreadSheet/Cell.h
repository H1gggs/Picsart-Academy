#pragma once
#include <iostream>
#include "Date.h"
#include "SpreadSheet.h"
enum class color {
	red,
	green,
	blue,
	white,
	black,
	no_color
};
class Cell {
private:
	std::string m_value;
	color m_color;
public:
	Cell();
	~Cell();
	Cell(const std::string&, const color&);
	void SetValue(std::string&);
	std::string GetValue();
	int ToInt();
	double ToDouble();
	Date ToDate();
	void Reset();
	bool operator== (Cell&);
	friend class SpreadSheet;
};
