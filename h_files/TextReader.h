#ifndef TEXTREADER_H
#define TEXTREADER_H

#include "Memory.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class TextReader{
  private:
    string fileName;
    // values at 24, 28, 32, 35
    string DBinsert = "INSERT INTO Words VALUES(, '', '', );";

  public:
    TextReader(const string textFile);
    ~TextReader();

    void readFileByWords(Memory DB);
    void printFileName();


};
#endif
