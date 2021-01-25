#ifndef TEXTREADER_H
#define TEXTREADER_H

#include <string>
#include <iostream>

using namespace std;

class TextReader{
  private:
    string fileName;

  public:
    TextReader(const string textFile);
    ~TextReader();

    void printFileName();


};
#endif
