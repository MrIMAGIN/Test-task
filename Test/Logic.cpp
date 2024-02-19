#include "Logic.h"

Logic::Logic(string name_db1, string name_tb1, string name_db2, string name_tb2)
	: _name_db1(name_db1)
	, _name_db2(name_db2)
	, _name_tb1(name_tb1)
	, _name_tb2(name_tb2)
{}

void Logic::calculate()
{
	reset();

	DataBase::openDataBase(db, _name_db1, _name_tb1, data);

	for (auto& elem : data) {
		_hashmap1.push_back(hashFunc(elem));
	}

	cout << endl;

	reset();

	DataBase::openDataBase(db, _name_db2, _name_tb2, data);

	for (auto& elem : data) {
		_hashmap2.push_back(hashFunc(elem));
	}
	cout << endl;

	if (_hashmap1.size() < _hashmap2.size()) {
		for (size_t i = 0; i < _hashmap2.size(); i++) {

			if (Search(_hashmap2[i], _hashmap1)) {
				cout << "In db1 not Found - id: " << i + 1 << endl;
			}
		}
	}

	if (_hashmap1.size() > _hashmap2.size()) {
		for (size_t i = 0; i < _hashmap1.size(); i++) {

			if (Search(_hashmap1[i], _hashmap2)) {
				cout << "In db2 not Found - id: " << i + 1 << endl;
			}
		}
	}

	if (_hashmap1.size() == _hashmap2.size()) {
		for (size_t i = 0; i < _hashmap1.size(); i++) {

			if (Search(_hashmap1[i], _hashmap2)) {
				cout << "In db2 not Found - id: " << i + 1 << endl;
			}
		}
	}
	
}

int64_t Logic::hashFunc(string& s)
{
	int64_t hash = 0;
	int64_t p_pow = 1;

	for (auto& elem : s) {
		hash += (elem - 'a' + 1) * p_pow;
		p_pow *= p;
	}

	return hash;
}

void Logic::reset()
{
	data.clear();
}

size_t Logic::interpolationSearch(int64_t toFind)
{
	size_t mid = 0;
	size_t low = 0;
	size_t high = _hashmap2.size() - 1;
	bool found;

	for (found = false; (_hashmap2[low] < toFind) && (_hashmap2[high] > toFind) && !found; )
	{
		mid = low + ((toFind - _hashmap2[low]) * (high - low)) / (_hashmap2[high] - _hashmap2[low]);
		if (_hashmap2[mid] < toFind)
			low = mid + 1;
		else if (_hashmap2[mid] > toFind)
			high = mid - 1;
		else
			found = true;
	}

	if (_hashmap2[low] == toFind || _hashmap2[high] == toFind) {
		return 0;
	}

	if (_hashmap2[mid] == toFind) {
		return 0;
	}

	return 1;
}

size_t Logic::Search(int64_t toFind, vector<int64_t> data)
{

	bool flag = false;

	for (auto& elem : data)
	{
		if (elem == toFind) {
			flag = true;
			break;
		}
	}
	
	if (flag == false) {
		return 1;
	}
	else {
		return 0;
	}
}
