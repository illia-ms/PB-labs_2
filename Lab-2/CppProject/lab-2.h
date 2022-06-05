#pragma once
#ifndef LAB_2_H

#define LAB_2_H

#include <iostream>
#include <ctime>
#include <fstream>
#include <cstring>
using namespace std;

struct Writing
{
    char title[70]{};
    int day{};
    int month{};
    int year{};
    int publication_year{};
};

void writeFile(const string &, Writing *, int);
void readFile(const string &, const string &);
void setWritings(Writing *&, int &);
void writeNewFile(const string &, const string &);
void showWritings(const string &);
void addWritings(const string &);

#endif //LAB_2_H
