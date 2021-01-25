#include "../h_files/TextReader.h"

#include <iostream>

using namespace std;

int main() {
    cout << "Hello World!\n";

    TextReader reader("test.txt");
    reader.printFileName();
    return 0;
}
