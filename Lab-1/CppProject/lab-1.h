#pragma once
#ifndef LAB_1_H
#define LAB_1_H

#include <iostream>
#include <fstream>
using namespace std;

void readFile(const string &, const string &);
void writeFile(const string &);
// Function that creates a new file with trimmed strings of an old one
void writeNewFile(const string &, const string &);
// Function for trimming given string
string trim(string);

#endif //LAB_1_H
