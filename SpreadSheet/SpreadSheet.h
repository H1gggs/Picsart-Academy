#pragma once
#include<iostream>
#include <vector>
#include "Cell.h"
#include "Date.h"
class Cell;
class SpreadSheet {
private:
	int Row;
	int Col;
	Cell** Cells;
public:
	SpreadSheet();
	~SpreadSheet();
	SpreadSheet(int, int);
	void SetCellAt(int, int, const Cell&);
	void SetCellAt(int, int, const std::string&);
	Cell GetCellAt(int, int);
	void AddRow(int);
	void RemoveRow(int);
	void AddColumn(int);
	void RemoveColumn(int);
	void SwapRows(int, int);
	void SwapColumns(int, int);
};
