#include "../h_files/TextReader.h"

using namespace std;

TextReader::TextReader(const string textFile){
  fileName = textFile;

}

TextReader::~TextReader(){

}

void TextReader::printFileName(){
  cout << "The filename is: " << fileName << "\n";

}
