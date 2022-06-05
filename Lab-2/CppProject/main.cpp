#include <iostream>
#include "lab-2.h"

using namespace std;

int main() {

    string path1 = "File-1.txt";
    string path2 = "File-2.txt";
    addWritings(path1);
    writeNewFile(path1, path2);
    readFile(path1, path1);
    readFile(path2, path2);
    showWritings(path1);

    return 0;
}
