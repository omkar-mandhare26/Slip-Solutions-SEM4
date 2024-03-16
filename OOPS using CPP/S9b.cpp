#include <iostream>
using namespace std;

class Time
{
    int hh, mm, ss;

public:
    void getTime()
    {
        cout << "Enter time in hh:mm:ss format: ";
        cin >> hh >> mm >> ss;
    }

    void displayTime()
    {
        cout << "Time in hh:mm:ss format: ";
        cout << hh << ":" << mm << ":" << ss;
    }

    void findDiff(Time T)
    {
        }
};

int main()
{

    return 0;
}