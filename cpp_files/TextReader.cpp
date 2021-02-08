#include "../h_files/TextReader.h"


using namespace std;

TextReader::TextReader(const string textFile){
  fileName = textFile;
}

TextReader::~TextReader(){

}

void TextReader::readFileByWords(Memory DB){
  ifstream inFile(fileName);

  if(inFile.is_open()){

    string word;
    string substring;
    string insert;
    int identifier = 0;

    int i = 0;
    while(i < 14){//(inFile >> word){
      i++;
      inFile >> word;
      for(auto c : word){
        if(!ispunct(c) || c == '\''){
          substring += c;
          identifier += (int)c;
        }
      }
      insert = DBinsert;
      //edit these when table name changes
      insert.insert(35, to_string(substring.size()));
      insert.insert(32, "google the type of word");
      insert.insert(28, substring);
      insert.insert(25, to_string(identifier));
      DB.populate(insert);

      substring = "";
      identifier = 0;
    }
  inFile.close();
  }
  else{
    cout << "Failed to open " << fileName << ".\n";
  }
}

void TextReader::printFileName(){
  cout << "The filename is: " << fileName << "\n";
}
