#include <iostream>
using namespace std;

class Time
{
public:
    int hh, mm, ss;

public:
    Time() {}
    Time(int h, int m, int s)
    {
        hh = h;
        mm = m;
        ss = s;
    }

    void getTime()
    {
        cout << "Enter time in hh:mm:ss format: ";
        cin >> hh >> mm >> ss;
    }

    void displayTime()
    {
        cout << "Time in hh:mm:ss format: ";
        cout << hh << ":" << mm << ":" << ss << "\n\n";
    }

    Time findDiff(Time T)
    {

        int second1 = (hh * 3600) + (mm * 60) + ss;
        int second2 = (T.hh * 3600) + (T.mm * 60) + T.ss;
        int diff = 0;
        if (second1 > second2)
            diff = second1 - second2;
        else
            diff = second2 - second1;

        int h = diff / 3600;
        diff %= 3600;

        int m = diff / 60;
        diff %= 60;

        Time temp(h, m, diff);
        return temp;
    }
};

int main()
{
    Time t1, t2;
    t1.getTime();
    t1.displayTime();

    t2.getTime();
    t2.displayTime();

    Time t3 = t1.findDiff(t2);
    t3.displayTime();
    return 0;
}