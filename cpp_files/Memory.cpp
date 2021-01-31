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
// static int exec_callback(void* data, int argc, char** argv, char** azColName)
// {
//     int i;
//     fprintf(stderr, "%s: ", (const char*)data);
//
//     for (i = 0; i < argc; i++) {
//         printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
//     }
//
//     printf("\n");
//     return 0;
//}

//### Class Functions
Memory::Memory(){

}

Memory::~Memory(){

}

void Memory::open(const char* database){

  int exit = sqlite3_open(database, &DB);

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

void Memory::populate(string insert){

    cout << "Populating db with insert command:\n" << insert << endl;

}
