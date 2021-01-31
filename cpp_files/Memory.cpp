#include "../h_files/Memory.h"

using namespace std;

//### Non Specific Functions
/*
 * Arguments:
 *
 *   data - Ignored in this case, see the documentation for sqlite3_exec
 *    argc - The number of columns in the result set
 *     argv - The row's data
 *  azColName - The column names
 */
static int exec_callback(void* data, int argc, char** argv, char** azColName)
{
    int i;
    fprintf(stderr, "%s: ", (const char*)data);

    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }

    printf("\n");
    return 0;
}

//### Class Functions
Memory::Memory(){

}

Memory::~Memory(){

}

void Memory::open(){

  int exit = sqlite3_open("Database/Memory.db", &DB);

  if (exit) {
      cerr << "Database Failed to Open: " << sqlite3_errmsg(DB) << endl;
  }
  else
      cout << "Opened Database Successfully!" << endl;
}

void Memory::close(){

  int exit = sqlite3_close(DB);

  if (exit) {
      cerr << "Database Failed to Close: " << sqlite3_errmsg(DB) << endl;
  }
  else
      cout << "Closed Database Successfully!" << endl;
}

void Memory::createTable(){
    char* messaggeError;
    int exit = sqlite3_exec(DB, data.c_str(), NULL, 0, &messaggeError);

    if (exit != SQLITE_OK) {
        cerr << "Error: Failed to create Table;" << endl;
        sqlite3_free(messaggeError);
    }
    else
        cout << "Table created Successfully" << endl;
}

void Memory::populate(){
    char* messaggeError;
    string query = "SELECT * FROM PERSON;";

    cout << "STATE OF TABLE BEFORE INSERT" << endl;

    sqlite3_exec(DB, query.c_str(), exec_callback, NULL, NULL);

    string sql("INSERT INTO Word VALUES(1, 'STEVE', 'GATES', 30, 'PALO ALTO', 1000.0);"
               "INSERT INTO Word VALUES(2, 'BILL', 'ALLEN', 20, 'SEATTLE', 300.22);"
               "INSERT INTO Word VALUES(3, 'PAUL', 'JOBS', 24, 'SEATTLE', 9900.0);");

    int exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
        cerr << "Error Insert" << endl;
        sqlite3_free(messaggeError);
    }
    else
        cout << "Records created Successfully!" << endl;

    cout << "STATE OF TABLE AFTER INSERT" << endl;

    sqlite3_exec(DB, query.c_str(), exec_callback, NULL, NULL);

    sql = "DELETE FROM PERSON WHERE ID = 2;";
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
        cerr << "Error DELETE" << endl;
        sqlite3_free(messaggeError);
    }
    else
        cout << "Record deleted Successfully!" << endl;

    cout << "STATE OF TABLE AFTER DELETE OF ELEMENT" << endl;
    sqlite3_exec(DB, query.c_str(), exec_callback, NULL, NULL);

}
