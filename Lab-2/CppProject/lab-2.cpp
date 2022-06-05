#include "lab-2.h"

void writeFile(const string &path, Writing *writings, const int num)
{
    ofstream outFile(path, ios::app | ios::binary);
    if (!outFile.is_open())
    {
        cout << "File execution error!" << endl;
    } else
    {
        outFile.write((char*)writings, num * sizeof(Writing));
    }
    outFile.close();
}

void readFile(const string &path, const string &header)
{
    ifstream inFile(path, ios::binary);
    if (!inFile.is_open())
    {
        cout << "File execution error!" << endl;
    } else
    {
        int i = 0;
        Writing writing;
        cout << endl << header << endl;
        while (inFile.read((char*)&writing, sizeof(Writing)))
        {
            cout << "==============================================" << endl;
            cout << "Writing " << ++i << endl;
            cout << "Title: " << writing.title << endl;
            cout << "Writing date: " << writing.day << '.' << writing.month << '.'
                 << writing.year << endl;
            writing.publication_year ? cout << "Publication year: " << writing.publication_year << endl :
            cout << "Writing was not published!" << endl;
        }
        cout << "==============================================" << endl;
    }
    inFile.close();
}

void setWritings(Writing *&writings, int &num)
{
    cout << "Enter the number of writings:";
    cin >> num;
    writings = new Writing[num];
    for (int i = 0; i < num; ++i) {
        cout << endl;
        cout << "Writing " << i + 1 << endl;
        cout << "Enter the title:";
        cin.ignore();
        fgets(writings[i].title, 70, stdin);
        writings[i].title[strlen(writings[i].title) - 1] = '\0';
        cout << "Enter the writing date:";
        cin >> writings[i].day;
        cin.get();
        cin >> writings[i].month;
        cin.get();
        cin >> writings[i].year;
        cout << "Enter the publication year:";
        cin >> writings[i].publication_year;
    }
}

void writeNewFile(const string &oldFile, const string &newFile)
{
    ifstream inFile(oldFile, ios::binary);
    ofstream outFile(newFile, ios::binary);
    if (!outFile.is_open() || !inFile.is_open())
    {
        cout << "File execution error!" << endl;
    } else
    {
        Writing writing;
        time_t cur_time = time(nullptr);
        tm *ltm = localtime(&cur_time);
        while (inFile.read((char*)&writing, sizeof(Writing)))
        {
            if ((1900 + ltm->tm_year) - writing.year < 4)
            {
                outFile.write((char*)&writing, sizeof(Writing));
            }
            else if ((1900 + ltm->tm_year) - writing.year == 4)
            {
                if ((1 + ltm->tm_mon) < writing.month)
                {
                    outFile.write((char*)&writing, sizeof(Writing));
                }
                else if ((1 + ltm->tm_mon) == writing.month)
                {
                    if (ltm->tm_mday <= writing.day)
                    {
                        outFile.write((char*)&writing, sizeof(Writing));
                    }
                }
            }
        }
    }
    outFile.close();
    inFile.close();
}

void showWritings(const string &path)
{
    ifstream inFile(path, ios::binary);
    if (!inFile.is_open())
    {
        cout << "File execution error!" << endl;
    } else
    {
        int i = 0;
        Writing writing;
        cout << endl << "Late published writings:" << endl;
        while (inFile.read((char*)&writing, sizeof(Writing)))
        {
            if (writing.publication_year - writing.year > 5)
            {
                cout << "==============================================" << endl;
                cout << "Writing " << ++i << endl;
                cout << "Title: " << writing.title << endl;
                cout << "Writing date: " << writing.day << '.' << writing.month << '.'
                     << writing.year << endl;
                cout << "Publication year: " << writing.publication_year << endl;
            }
        }
        cout << "==============================================" << endl;
    }
    inFile.close();
}

void addWritings(const string &path)
{
    int num;
    Writing *writings;
    setWritings(writings, num);
    writeFile(path, writings, num);
    delete[] writings;
}
