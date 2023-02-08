#include <iostream>
#include "Cell.h"
#include "Date.h"
#include "SpreadSheet.h"
class TDD {
public:
	void TestForCellAndSpreadSheet() {
		Date DMY(31, 12, 2013);
		color col = color::red;
		SpreadSheet testSS(4,4);
		Cell c("10", col);
		testSS.SetCellAt(1,1,c);
		if (c.ToInt() == 10) {
			std::cout << "test success" << std::endl;
		}
		else {
			std::cout << "test failed" << std::endl;
		}
		Cell c1("10.7", col);
		if (c1.ToDouble() == 10.7) {
			std::cout << "test success" << std::endl;
		}
		else {
			std::cout << "test failed" << std::endl;
		}
		Cell c2("31,-12,2013",col);
		if (c2.ToDate() == DMY) {
			std::cout << "test success" << std::endl;
		}
		else {
			std::cout << "test failed" << std::endl;
		}
		if (testSS.GetCellAt(1, 1) == c) {
			std::cout << "test success" << std::endl;
		}
		else {
			std::cout << "test failed" << std::endl;
		}
	}
};
int main() {
	TDD Test;
	Test.TestForCellAndSpreadSheet();
}