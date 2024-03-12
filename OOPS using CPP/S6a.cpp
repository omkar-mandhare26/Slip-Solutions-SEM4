#include <iostream>
using namespace std;

class Rectangle;

class Square
{
public:
    int l;

public:
    Square(int a)
    {
        l = a;
    }

    int area()
    {
        return l * l;
    }

    friend void compareArea(Square obj1, Rectangle obj2);
};

class Rectangle
{
public:
    int l, w;

public:
    Rectangle(int a, int b)
    {
        l = a;
        w = b;
    }

    int area()
    {
        return l * w;
    }

    friend void compareArea(Square obj1, Rectangle obj2);
};

void compareArea(Square obj1, Rectangle obj2)
{
    if (obj1.area() < obj2.area())
        cout << "Area of Square is less than Area of Rectangle";
    else
        cout << "Area of Square is greater than Area of Rectangle";
}

int main()
{
    Square s(5);
    Rectangle r(7, 2);

    cout << "Area of Square : " << s.area() << endl;
    cout << "Area of Rectangle: " << r.area() << endl;

    compareArea(s, r);
    return 0;
}