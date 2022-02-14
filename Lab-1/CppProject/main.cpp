#include <iostream>
#include "lab-1.h"

using namespace std;

int main() {

    string path1 = "myFile.txt";
    string path2 = "newFile.txt";
    writeFile(path1);
    readFile(path1, "Old File:");
    writeNewFile(path1, path2);
    readFile(path2, "New File:");

    return 0;
}
