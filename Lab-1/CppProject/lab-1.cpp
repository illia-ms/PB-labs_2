#include "lab-1.h"

string trim(string str)
{
    unsigned int start, end;
    if (str.find_first_not_of(' ') != string::npos)
    {
        start = str.find_first_not_of(' ');
        end = str.find_last_not_of(' ');
        end += 1 - start;
        return str.substr(start, end);
    }
    else
    {
        return str;
    }
}

void writeNewFile(const string &path1, const string &path2)
{
    ofstream outFile(path2);
    ifstream inFile(path1);
    if (!outFile.is_open() || !inFile.is_open())
    {
        cout << "File execution error!" << endl;
    } else
    {
        string s, new_s;
        int counter;
        bool isFirst = true;
        while (!inFile.eof())
        {
            new_s = "";
            counter = 0;
            getline(inFile, s);
            s = trim(s);
            if (s.find_first_not_of(' ') != string::npos)
            {
                for (char i: s) {
                    if ((int) i == 32) {
                        new_s += "  ";
                        counter++;
                    } else {
                        new_s += i;
                    }
                }
                if (!isFirst)
                {
                    outFile << endl;
                }
                outFile << new_s << " - " << counter;
            }
            else
            {
                if (!isFirst)
                {
                    outFile << endl;
                }
                outFile << s;
            }
            isFirst = false;
        }
    }
    outFile.close();
    inFile.close();
}

void writeFile(const string &path)
{
    ofstream outFile(path, ios::app);
    if (!outFile.is_open())
    {
        cout << "File execution error!" << endl;
    } else
    {
        string s;
        cout << "Your text:" << endl;
        while (true)
        {
            s = "";
            getline(cin, s);
            if (s.empty())
            {
                break;
            } else
            {
                outFile << s << endl;
            }
        }
    }
    outFile.close();
}

void readFile(const string &path, const string &header)
{
    ifstream inFile(path);
    if (!inFile.is_open())
    {
        cout << "File execution error!" << endl;
    } else
    {
        string s;
        cout << header << endl;
        while (!inFile.eof())
        {
            s = "";
            getline(inFile, s);
            cout << s << endl;
        }
    }
    inFile.close();
}
