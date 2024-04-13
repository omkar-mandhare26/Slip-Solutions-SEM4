#include <iostream>
using namespace std;

inline int findMax(int a, int b)
{
    return (a > b) ? a : b;
}

inline int findMin(int a, int b)
{
    return (a < b) ? a : b;
}

int main()
{
    int a, b;
    cout << "Enter No 1: ";
    cin >> a;

    cout << "Enter No 2: ";
    cin >> b;

    int max = findMax(a, b), min = findMin(a, b);
    cout << "Maximum number between " << a << " and " << b << " : " << max << endl;
    cout << "Minimum number between " << a << " and " << b << " : " << min;

    return 0;
}