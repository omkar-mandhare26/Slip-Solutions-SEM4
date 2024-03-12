#include <iostream>
using namespace std;

void interchange(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

int main()
{
    int a, b;
    cout << "Enter 2 numbers: ";
    cin >> a >> b;

    cout << "Value of a before swap: " << a << endl;
    cout << "Value of b before swap: " << b << endl;

    interchange(a, b);
    cout << "Value of a after swap: " << a << endl;
    cout << "Value of b after swap: " << b << endl;

    return 0;
}