#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class myfile
{
public:
    char filename[100];
    fstream file;

public:
    myfile() {}
    myfile(char *fname)
    {
        strcpy(filename, fname);
        file.open(filename, ios::in | ios::out);
    }

    void copyFileContent(const string &sourceFilename1, const string &sourceFilename2, const string &destinationFilename)
    {
        ifstream sourceFile1(sourceFilename1);
        ifstream sourceFile2(sourceFilename2);
        ofstream destinationFile(destinationFilename);

        char c;
        while ((c = sourceFile1.get()) != EOF)
        {
            destinationFile.put(c);
        }

        while ((c = sourceFile2.get()) != EOF)
        {
            destinationFile.put(c);
        }

        cout << "Content of " << sourceFilename1 << " copied to " << destinationFilename << endl;

        sourceFile1.close();
        destinationFile.close();
    }
};

int main()
{
    string sourceFilename1 = "file1.txt";
    string sourceFilename2 = "file2.txt";
    string destinationFilename = "file3.txt";
    myfile f;
    f.copyFileContent(sourceFilename1, sourceFilename2, destinationFilename);

    return 0;
}
