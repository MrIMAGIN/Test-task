#pragma once
#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
#include <algorithm>
#include "DataBase.h"
#include "appconstants.h"
#include "sqlite/sqlite3.h"

using namespace std;

class Logic
{
public:
	Logic() = default;
	Logic(string, string, string, string);

	void calculate();
	void reset();
	size_t interpolationSearch(int64_t toFind);
	size_t Search(int64_t toFind, vector<int64_t>);

	int64_t hashFunc(string&);

private:
	sqlite3* db;

	vector<string> data;
	vector<int64_t> _hashmap1;
	vector<int64_t> _hashmap2;

	string _name_db1;
	string _name_db2;
	string _name_tb1;
	string _name_tb2;
};