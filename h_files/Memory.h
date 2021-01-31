#ifndef MEMORY_H
#define MEMORY_H

#include <string>
#include <iostream>
#include <sqlite3.h>

using namespace std;

class Memory{
  private:
    sqlite3* DB;
    string data = "CREATE TABLE Word("
                      "ID INT PRIMARY KEY     NOT NULL, "
                      "Word           TEXT    NOT NULL, "
                      "TYPE          TEXT     NOT NULL, "
                      "LENGTH            INT     NOT NULL);";

  public:
    Memory();
    ~Memory();

    void open(const char* database);
    void close();
    void createTable();
    void populate(string insert);


};
#endif
