#include "../h_files/TextReader.h"
#include "../h_files/Memory.h"

#include <iostream>

using namespace std;

int main() {
    cout << "Hello World!\n";

    //TextReader reader("txt_files/test.txt");
    //reader.printFileName();

    Memory memory;
    memory.open();
    memory.createTable();
    memory.populate();
    memory.close();

    return 0;
}
