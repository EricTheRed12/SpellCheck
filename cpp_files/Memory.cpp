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

int callback(void* notUsedYet, int argc, char** argv, char** colName){

  cout << notUsedYet << "\n";

  for (int i = 0; i < argc; i++) {
        cout << colName[i] << " = " << argv[i] << "\n";
    }

  return 0;
}


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
    char* err_msg = 0;
    const char* msg = insert.c_str();

    cout << "Populating db with insert command:\n" << insert << endl;

    int exit =  sqlite3_exec(DB, msg, 0, 0, &err_msg);

    if (exit != SQLITE_OK ) {

        cout << "Failed to insert data, Error: " << err_msg << "\n";

        sqlite3_free(err_msg);
    }
}

void Memory::read(){

  cout << "Reading data: " << "\n";

  char* err_msg = 0;
  const char* read = "SELECT ID, Word FROM Words WHERE Length = 4"; //

  int exit =  sqlite3_exec(DB, read, callback, 0, &err_msg);

  if (exit != SQLITE_OK ) {

      cout << "Failed to read data, Error: " << err_msg << "\n";

      sqlite3_free(err_msg);
  }
}
