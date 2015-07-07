#include "general.h"
#include <sqlite3.h> 

/*Here, SQLite with C/C++ API is used, current it is a demo using  
 a given database in the directory databases*/

void SQLite()
{
	sqlite3 *db; // database
	int rc; // request check for SQLite
	char *zErrMsg = 0; // Error message provided by SQLite
	char *sql; // Query
	const char* data = "Callback function called";
	const char* datatable = "Table called";

	rc = sqlite3_open("./databases/test.db", &db); // Open the database
	if(rc) // Error Check
	{
		std::cerr <<  sqlite3_errmsg(db) << std::endl;
		exit(0);
	}
	// Table Checks
	sql = (char *)"SELECT name FROM sqlite_master WHERE type=\"table\"";
	rc = sqlite3_exec(db, sql, callback, (void*)datatable, &zErrMsg); 
	if(rc != SQLITE_OK) // Error Check
	{
		std::cerr << zErrMsg << std::endl;
		sqlite3_free(zErrMsg);
	}

	// Query Statement
	sql = (char *)"SELECT * FROM Employee where Country = \"Canada\";";

	// Execute the query statement (checking databases, tables are not
	// a query statement)
	rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg); 
	if(rc != SQLITE_OK) // Error Check
	{
		std::cerr << zErrMsg << std::endl;
		sqlite3_free(zErrMsg);
	}

	sqlite3_close(db); // Close the Database
}

int callback(void *data, int argc, char **argv, char **azColName)
{
	std::cerr << (const char*)data << std::endl;
	for(int i = 0; i < argc; i++)
		std::cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << std::endl;
	std::cout << std::endl;
	return 0;
}
