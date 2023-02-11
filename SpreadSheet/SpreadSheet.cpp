#include <iostream>
#include "SpreadSheet.h"
SpreadSheet::SpreadSheet() {}
SpreadSheet::~SpreadSheet() {}
SpreadSheet::SpreadSheet(int Row, int Col) {
	this->Row = Row;
	this->Col = Col;
	Cells.resize(Row, std::vector<Cell>(Col));
	for (int i = 0; i < Row; ++i) {
		for (int j = 0; j < Col; ++j) {
			Cells[i][j].m_value = "";
			Cells[i][j].m_color = color::no_color;
		}
	}
}
void SpreadSheet::SetCellAt(int row, int col, const Cell& cl) { 
	if ((row >= Row) || (col >= Col)) {
		std::cout << "invalid data" << std::endl;
		return;
	}
	if ((row < 0) || (col < 0)) {
		std::cout << "invalid data" << std::endl;
		return;
	}
	Cells[row][col].m_color = cl.m_color;
	Cells[row][col].m_value = cl.m_value;
}
void SpreadSheet::SetCellAt(int row, int col,const std::string& str) { 
	if ((row >= Row) || (col >= Col)) {
		std::cout << "invalid data" << std::endl;
		return;
	}
	if ((row < 0) || (col < 0)) {
		std::cout << "invalid data" << std::endl;
		return;
	}
	Cells[row][col].m_value = str;
	Cells[row][col].m_color = color::no_color;
}
Cell SpreadSheet::GetCellAt(int row, int col) { 
	if ((row >= Row) || (col >= Col)) {
		std::cout << "invalid data" << std::endl;
		return Cells[-1][-1];
	}
	if ((row < 0) || (col < 0)) {
		std::cout << "invalid data" << std::endl;
		return Cells[-1][-1];
	}
	return Cells[row][col];

}
void SpreadSheet::AddRow(int row) {
	if (row >= Row) {
		std::cout << "invalid data" << std::endl;
		return;
	}
	if (row < 0) {
		std::cout << "invalid data" << std::endl;
		return;
	}
	int Tmp_Row = Row + 1;
	std::vector<std::vector<Cell>> Tmp_Cells;
	Tmp_Cells.resize(Tmp_Row, std::vector<Cell>(Col));
	for (int i = 0; i < Tmp_Row; ++i) {
		for (int j = 0; j < Col; ++j) {
			Tmp_Cells[i][j].m_value = "";
			Tmp_Cells[i][j].m_color = color::no_color;
		}
	}
	int k = 0;

	for (; k < row; ++k) {
		for (int i = 0; i < Col; ++i) {
			Tmp_Cells[k][i].m_value = this->Cells[k][i].m_value;
			Tmp_Cells[k][i].m_color = this->Cells[k][i].m_color;
		}
	}
	for (int i = row + 1; i < Tmp_Row; ++i) {
		for (int j = 0; j < Col; ++j) {
			Tmp_Cells[i][j].m_value = this->Cells[k][j].m_value;
			Tmp_Cells[i][j].m_color = this->Cells[k][j].m_color;
		}
		k++;
	}
	Row++;
	Cells.resize(Row, std::vector<Cell>(Col));
	for (int i = 0; i < Row; ++i) {
		for (int j = 0; j < Col; ++j) {
			this->Cells[i][j].m_value = Tmp_Cells[i][j].m_value;
			this->Cells[i][j].m_color = Tmp_Cells[i][j].m_color;
		}
	}
}
void SpreadSheet::RemoveRow(int row) {
	int Tmp_Row = Row - 1;
	std::vector<std::vector<Cell>> Tmp_Cells;
	Tmp_Cells.resize(Tmp_Row, std::vector<Cell>(Col));
	for (int i = 0,index = 0; i < Row; i++)
	{
		if (i == row)
		{
			continue;
		}
		for (int j = 0; j < Col; j++)
		{
			Tmp_Cells[index][j] = Cells[i][j];
		}
		index++;
	}
	Row--;
	Cells.resize(Row, std::vector<Cell>(Col));
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{

			Cells[i][j] = Tmp_Cells[i][j];
		}
	}
}
void SpreadSheet::AddColumn(int col) { 
	int Tmp_Col = Col + 1;
	std::vector<std::vector<Cell>> Tmp_Cells;
	Tmp_Cells.resize(Row, std::vector<Cell>(Tmp_Col));
	for (int i = 0; i < Row; ++i) {
		for (int j = 0; j < Tmp_Col; ++j) {
			Tmp_Cells[i][j].m_value = "";
			Tmp_Cells[i][j].m_color = color::no_color;
		}
	}
	for (int i = 0; i < Row; ++i) {
		int k = 0;
		for (int j = 0; j < Tmp_Col; ++j) {
			if (k >= Col) {
				std::cout << "Error" << std::endl;
			}
			if (j == col) {
				continue;
			}
			Tmp_Cells[i][j].m_value = Cells[i][k].m_value;
			Tmp_Cells[i][j].m_color = Cells[i][k].m_color;
			k++;
		}
	}
	std::vector<std::vector<Cell>> V_Arr(Row, std::vector<Cell>(Col+1));
	this->Cells = V_Arr;
	Col++;
	for (int i = 0; i < Row; ++i) {
		for (int j = 0; j < Col; ++j) {
			this->Cells[i][j].m_value = Tmp_Cells[i][j].m_value;
			this->Cells[i][j].m_color = Tmp_Cells[i][j].m_color;
		}
	}
}
void SpreadSheet::RemoveColumn(int col) { 
	int Tmp_Col = Col - 1;
	std::vector<std::vector<Cell>> Tmp_Cells;
	Tmp_Cells.resize(Row, std::vector<Cell>(Tmp_Col));
	for (int i = 0; i < Row; ++i) {
		for (int j = 0; j < Tmp_Col; ++j) {
			Tmp_Cells[i][j].m_value = "";
			Tmp_Cells[i][j].m_color = color::no_color;
		}
	}
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0, index = 0; j < Col; j++)
		{
			if (j == col)
			{
				continue;
			}
			Tmp_Cells[i][index] = Cells[i][j];
			index++;
		}
	}	
	std::vector<std::vector<Cell>> V_Arr(Row, std::vector<Cell>(Col - 1));
	Cells = V_Arr;
	Col--;
	for (int i = 0; i < Row; ++i) {
		for (int j = 0; j < Col; ++j) {
			this->Cells[i][j].m_value = Tmp_Cells[i][j].m_value;
			this->Cells[i][j].m_color = Tmp_Cells[i][j].m_color;
		}
	}
}
void SpreadSheet::SwapRows(int R1, int R2) { 
	if ((R1 >= Row) || (R2 >= Row)) {
		std::cout << "invalid data" << std::endl;
	}
	if ((R1 < 0) || (R2 < 0)) {
		std::cout << "invalid data" << std::endl;
	}
	for (int i = 0; i < Col; ++i) {
		std::swap(Cells[R1][i],Cells[R2][i]);
	}
}
void SpreadSheet::SwapColumns(int C1, int C2) {
	if ((C1 >= Col) || (C2 >= Col)) {
		std::cout << "invalid data" << std::endl;
	}
	if ((C1 < 0) || (C2 < 0)) {
		std::cout << "invalid data" << std::endl;
	}
	for (int i = 0; i < Col; ++i) {
		std::swap(Cells[i][C1], Cells[i][C2]);
	}
}
