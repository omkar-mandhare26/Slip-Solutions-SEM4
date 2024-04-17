#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "Not enough args";
        return 1;
    }

    ofstream evenFile("Even.txt");
    ofstream oddFile("Odd.txt");

    for (int i = 1; i < argc; ++i)
    {
        int num = atoi(argv[i]);
        if (num % 2 == 0)
            evenFile << num << endl;
        else
            oddFile << num << endl;
    }
    cout << "Even numbers stored in Even.txt" << endl;
    cout << "Odd numbers stored in Odd.txt" << endl;

    evenFile.close();
    oddFile.close();

    return 0;
}
