#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
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
    }

    void readfile()
    {
        ifstream infile(filename);
        char c;
        while ((c = infile.get()) != EOF)
        {
            cout << c;
        }
    }

    void operator!()
    {
        const int bufferSize = 1024;
        char buffer[bufferSize];
        int index = 0;
        char c;

        ifstream infile(filename);
        while (infile.get(c))
        {
            if (islower(c))
                c = toupper(c);
            else if (isupper(c))
                c = tolower(c);

            buffer[index++] = c;

            if (index >= bufferSize - 1)
            {
                buffer[index] = '\0';
                ofstream outfile(filename, ios::app);
                outfile << buffer;
                outfile.close();
                index = 0;
            }
        }
        infile.close();

        if (index > 0)
        {
            buffer[index] = '\0';
            ofstream outfile(filename, ios::app);
            outfile << buffer;
            outfile.close();
        }
    }

    myfile operator+(const myfile &obj)
    {
        myfile temp;
        char filename3[] = "file3.txt";
        strcpy(temp.filename, filename3);

        ifstream file1(filename);
        ifstream file2(obj.filename);
        ofstream file3(filename3);
        char c;
        while ((c = file1.get()) != EOF)
            file3.put(c);

        while ((c = file2.get()) != EOF)
            file3.put(c);

        file1.close();
        file3.close();

        return temp;
    }
};

int main()
{
    char file1[] = "file1.txt";
    char file2[] = "file2.txt";
    myfile f1(file1), f2(file2);

    myfile f3 = f1 + f2;
    !f3;
    f3.readfile();

    return 0;
}
