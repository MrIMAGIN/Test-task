#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "sqlite/sqlite3.h"

using namespace std;

class DataBase
{
public:
	static void openDataBase(sqlite3*, string, string, vector<string>&);
	static int callback(void*, int, char**, char**);
};

