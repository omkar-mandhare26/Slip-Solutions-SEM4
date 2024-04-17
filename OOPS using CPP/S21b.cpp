#include <iostream>
using namespace std;

class Points
{
public:
    int x, y;

public:
    Points() {}
    Points(int a, int b) : x(a), y(b) {}

    void display()
    {
        cout << "Points: " << x << ", " << y << endl;
    }

    Points operator+(Points &p)
    {
        Points temp;
        temp.x = x + p.x;
        temp.y = y + p.y;

        return temp;
    }

    void operator-()
    {
        x = -x;
        y = -y;
    }

    Points operator*(int n)
    {
        Points temp;
        temp.x = x * n;
        temp.y = y * n;

        return temp;
    }
};

int main()
{
    Points p1(4, 7);
    Points p2 = p1 * 3;
    Points p3 = p1 + p2;
    -p1;

    p1.display();
    p2.display();
    p3.display();
    return 0;
}