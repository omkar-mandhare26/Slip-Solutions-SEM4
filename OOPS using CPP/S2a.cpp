#include <iostream>
using namespace std;
float PI = 3.14;

void calVolume(int r, int h)
{
    cout << "Volume of cylinder : " << PI * (r * r) * h << endl;
}

void calVolume(int r, int h, bool cone)
{
    if (cone)
        cout << "Volume of Cone : " << PI * (r * r) * h / 3 << endl;
}

void calVolume(int r)
{
    cout << "Volume of Sphere: " << 4.0 / 3.0 * PI * (r * r * r) << endl;
}

int main()
{
    int r, h;
    cout << "Enter radius and height of a cylinder: ";
    cin >> r >> h;
    calVolume(r, h);

    cout << "Enter radius and height of a cone: ";
    cin >> r >> h;
    calVolume(r, h, true);

    cout << "Enter radius a sphere: ";
    cin >> r;
    calVolume(r);

    return 0;
}