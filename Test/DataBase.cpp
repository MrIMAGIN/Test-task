#include "DataBase.h"

void DataBase::openDataBase(sqlite3* db, string name_db, string name_table, vector<string>& data)
{
	char* err_msg = 0;

	if (sqlite3_open(name_db.c_str(), &db) != SQLITE_OK) {
		cout << "error to open database: " << sqlite3_errmsg(db) << endl;
		sqlite3_close(db);
	}
	else {
		cout << name_db + " is open." << endl;

		string sql = "SELECT * FROM " + name_table;
		if (sqlite3_exec(db, sql.c_str(), callback, &data, &err_msg) != SQLITE_OK) {
			cout << "SQL error: " << err_msg << endl;
			sqlite3_free(err_msg);
			sqlite3_close(db);
		}

		sqlite3_close(db);
	}
}

int DataBase::callback(void* data, int colCount, char** columns, char** colNames)
{
	string str;

	for (int i = 1; i < colCount; i++) {
		str += columns[i];
	}

	reinterpret_cast<vector<string>*>(data)->push_back(str);

	return 0;
}
