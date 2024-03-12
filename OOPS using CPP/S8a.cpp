#include <iostream>
using namespace std;

class Number
{
public:
    static int cnt;

public:
    static void display()
    {
        cout << "Value of num: " << cnt << endl;
    }
};

int main()
{
    Number num;
    num.display();
    num.display();
    num.display();

    return 0;
}