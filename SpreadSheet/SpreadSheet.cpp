#include <iostream>
#include "SpreadSheet.h"
SpreadSheet::SpreadSheet() {}
SpreadSheet::~SpreadSheet() {
	for (int i = 0; i < Row; ++i) {
		delete[] Cells[i];
		Cells[i] = nullptr;
	}
	delete[] Cells;
	Cells = nullptr;
}
SpreadSheet::SpreadSheet(int Row, int Col) {
	this->Row = Row;
	this->Col = Col;
	Cells = new Cell * [Col];
	for (int i = 0; i < Row; ++i) {
		Cells[i] = new Cell[Col];			
	}
	for (int i = 0; i < Row; ++i) {
		for (int j = 0; j < Col; ++j) {
			Cells[i][j].m_value = "";
			Cells[i][j].m_color = color::no_color;
		}
	}
}
void SpreadSheet::SetCellAt(int row, int col, const Cell& cl) {  
	Cells[row][col].m_color = cl.m_color;
	Cells[row][col].m_value = cl.m_value;
}
void SpreadSheet::SetCellAt(int row, int col,const std::string& str) { 
	Cells[row][col].m_value = str;
	Cells[row][col].m_color = color::no_color;
}
Cell SpreadSheet::GetCellAt(int row, int col) { 
	
	return Cells[row][col];

}
void SpreadSheet::AddRow(int row) {
	int Tmp_Row = Row + 1;
	Cell** Tmp_Cells;
	Tmp_Cells = new Cell * [Col];
	for (int i = 0; i < Tmp_Row; ++i) {
		Tmp_Cells[i] = new Cell[Col];		
	}
	for (int i = 0; i < Tmp_Row; ++i) {
		for (int j = 0; j < Col; ++j) {
			Tmp_Cells[i][j].m_value = "";
			Tmp_Cells[i][j].m_color = color::no_color;
		}
	}
	int k = 0;

	for (; k < row; ++k) {
		for (int i = 0; i < Col; ++i) {
			Tmp_Cells[k][i].m_value = Cells[k][i].m_value;
			Tmp_Cells[k][i].m_color = Cells[k][i].m_color;
		}
	}
	for (int i = row + 1; i < Tmp_Row; ++i) {
		for (int j = 0; j < Col; ++j) {
			Tmp_Cells[i][j].m_value = Cells[k][j].m_value;
			Tmp_Cells[i][j].m_color = Cells[k][j].m_color;
		}
		k++;
	}
	for (int i = 0; i < Row; ++i) {
		delete[] Cells[i];
	}
	delete[] Cells;
	Row++;
	Cells = new Cell * [Col];
	for (int i = 0; i < Row; ++i) {
		Cells[i] = new Cell[Col];
	}
	for (int i = 0; i < Row; ++i) {
		for (int j = 0; j < Col; ++j) {
			Cells[i][j].m_value = Tmp_Cells[i][j].m_value;
			Cells[i][j].m_color = Tmp_Cells[i][j].m_color;
		}
	}
	for (int i = 0; i < Tmp_Row; ++i) {
		delete[] Tmp_Cells[i];
	}
	delete[] Tmp_Cells;

}
void SpreadSheet::RemoveRow(int row) {
	Cell** newCells = new Cell * [Row-1];
	for (int i = 0; i < Row-1; i++)
	{
		newCells[i] = new Cell[Col];
	}

	for (int i = 0,newRoW = 0; i < Row; i++)
	{
		if (i == row)
		{
			continue;
		}
		for (int j = 0; j < Col; j++)
		{
			newCells[newRoW][j] = Cells[i][j];
		}
		newRoW++;
	}
	Row--;
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{

			Cells[i][j] = newCells[i][j];
		}
	}
}
void SpreadSheet::AddColumn(int col) { 
	int Tmp_Col = col + 1;
	Cell** Tmp_Cells;
	Tmp_Cells = new Cell * [Tmp_Col];
	for (int i = 0; i < Row; ++i) {
		Tmp_Cells[i] = new Cell[Tmp_Col];
	}
	for (int i = 0; i < Row; ++i) {
		for (int j = 0; j < Tmp_Col; ++j) {
			Tmp_Cells[i][j].m_value = "";
			Tmp_Cells[i][j].m_color = color::no_color;
		}
	}
	int k = 0;
	for (int i = 0; i < Row; ++i) {
		for (int k = 0; k < col; ++k) {
			Tmp_Cells[i][k].m_value = Cells[i][k].m_value;
			Tmp_Cells[i][k].m_color = Cells[i][k].m_color;
		}
	}
	for (int i = 0; i < Row; ++i) {
		for (int j = col+1; j < Tmp_Col; ++j) {
			Tmp_Cells[i][j].m_value = Cells[i][k].m_value;
			Tmp_Cells[i][j].m_color = Cells[i][k].m_color;
		}
		k++;
	}
	for (int i = 0; i < Row; ++i) {
		delete[] Cells[i];
	}
	delete[] Cells;
	Col++;
	Cells = new Cell * [Col];
	for (int i = 0; i < Row; ++i) {
		Cells[i] = new Cell[Col];
	}
	for (int i = 0; i < Row; ++i) {
		for (int j = 0; j < Col; ++j) {
			Cells[i][j].m_value = Tmp_Cells[i][j].m_value;
			Cells[i][j].m_color = Tmp_Cells[i][j].m_color;
		}
	}
	for (int i = 0; i < Row; ++i) {
		delete[] Tmp_Cells[i];
	}
	delete[] Tmp_Cells;
}
void SpreadSheet::RemoveColumn(int col) { 
	Cell** newCells = new Cell* [Row];
	for (int i = 0; i < Row; i++)
	{
		newCells[i] = new Cell[Col - 1];
	}

	for (int i = 0; i < Row; i++)
	{
		for (int j = 0, newCol = 0; j < Col; j++)
		{
			if (j == col)
			{
				continue;
			}
			newCells[i][newCol] = Cells[i][j];
			newCol++;
		}
	}
	Col--;
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{

			Cells[i][j] = newCells[i][j];
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