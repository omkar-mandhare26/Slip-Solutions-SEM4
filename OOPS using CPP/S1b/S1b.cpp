#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

class myFile
{
public:
    fstream file;
    char fileName[25];

public:
    myFile() {}

    myFile(char *filename)
    {
        strcpy(fileName, filename);
    }

    void display()
    {
        char line[100];
        file.open(fileName, ios::in | ios::out);
        file.read((char *)&line, sizeof(line));
        cout << line << endl;
    }

    myFile operator+(myFile obj)
    {
        myFile temp;

        // ofstream outfile(outfilename);
        // ifstream infile1(fileName);
        // ifstream infile2("file2.txt");

        char ch;
        while (infile1.get(ch))
        {
            outfile.put(ch);
        }
        while (infile2.get(ch))
        {
            outfile.put(ch);
        }
    }
};

int main()
{
    char filename[] = {"file1.txt"};
    char outfilename[] = {"file3.txt"};
    myFile f(filename);
    f.display();
    f.append(outfilename);

    return 0;
}