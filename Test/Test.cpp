#include <iostream>
#include <string>
#include "Logic.h"

using namespace std;

int main()
{
	Logic logic("DataBase1.sqlite", "table1", "DataBase2(1).sqlite", "table2");

	logic.calculate();

	return 0;
}

