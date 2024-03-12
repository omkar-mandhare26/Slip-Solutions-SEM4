#include <iostream>
using namespace std;

class Point
{
public:
    int x, y;

public:
    void setpoint(int a, int b)
    {
        x = a;
        y = b;
    }

    void showPoint()
    {
        cout << "(" << x << "," << y << ")";
    }
};

int main()
{
    Point P;
    P.setpoint(7, 8);
    P.showPoint();
    return 0;
}