#include <iostream>
using namespace std;

class Fraction
{
public:
    int numerator, denominator;

public:
    Fraction() {}
    Fraction(int n, int d)
    {
        numerator = n;
        denominator = d;
    }

    void displayFraction()
    {
        cout << numerator << "/" << denominator << endl;
    }

    Fraction operator+(Fraction obj)
    {
        Fraction temp;
        if (denominator == obj.denominator)
        {
            temp.numerator = numerator + obj.numerator;
            temp.denominator = denominator;
        }
        else
        {
            temp.numerator = numerator * obj.denominator + obj.numerator * denominator;
            temp.denominator = denominator * obj.denominator;
        }
        return temp;
    }
};

int main()
{
    Fraction *obj1 = new Fraction(2, 7);
    Fraction *obj2 = new Fraction(5, 7);

    cout << "First Fraction: ";
    obj1->displayFraction();

    cout << "Second Fraction: ";
    obj2->displayFraction();

    Fraction obj3 = *obj1 + *obj2;
    cout << "Addition: ";
    obj3.displayFraction();

    // obj1->addFraction(*obj2);
    return 0;
}
