#include "../h_files/TextReader.h"
#include "../h_files/Memory.h"

#include <iostream>

using namespace std;

int main() {
    cout << "Hello World!\n";

    Memory memory;
    TextReader reader("txt_files/test.txt");

    memory.open("Database/words");
    memory.createTable();

    reader.readFileByWords(memory);
    //reader.printFileName();

    memory.close();

    return 0;
}
