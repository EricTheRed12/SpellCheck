#include "../h_files/TextReader.h"

using namespace std;

TextReader::TextReader(const string textFile){
  fileName = textFile;

  ifstream inFile(textFile);
  if(inFile.is_open()){
    string line;
    while(getline(inFile, line)){
      cout << line << "\n";
    }
    inFile.close();
  }
  else{
    cout << "Failed to open " << textFile << ".\n";
  }


}

TextReader::~TextReader(){

}

void TextReader::printFileName(){
  cout << "The filename is: " << fileName << "\n";

}
