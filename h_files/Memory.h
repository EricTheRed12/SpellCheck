#ifndef MEMORY_H
#define MEMORY_H

#include <string>
#include <iostream>
#include <sqlite3.h>

using namespace std;

class Memory{
  private:
    sqlite3* DB;
    string data = "CREATE TABLE Words("
                      "Id INT PRIMARY KEY     NOT NULL, "
                      "Word           TEXT    NOT NULL, "
                      "Typr          TEXT     NOT NULL, "
                      "Length            INT     NOT NULL);";

  public:
    Memory();
    ~Memory();

    void open(const char* database);
    void close();
    void createTable();
    void populate(string insert);
    void read();


};
#endif
