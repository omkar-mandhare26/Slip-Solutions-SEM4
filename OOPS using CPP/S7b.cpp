#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Vector
{
public:
    int size;
    int *p;

public:
    Vector() {}
    Vector(int size)
    {
        this->size = size;
        p = new int[size];
    }
    Vector(Vector &obj)
    {
        size = obj.size;
        p = new int[size];
        for (int i = 0; i < size; i++)
            p[i] = obj.p[i];
    }

    void getElements()
    {
        cout << "Enter " << size << " elements: ";
        for (int i = 0; i < size; i++)
            cin >> p[i];
    }

    void diplayVector()
    {
        cout << "Elements: ";
        for (int i = 0; i < size; i++)
        {
            cout << p[i];
            if (i < size - 1)
                cout << ", ";
        }
        cout << endl;
    }

    Vector createUnion(const Vector &obj)
    {
        int newSize = size + obj.size;
        Vector temp(newSize);
        int index = 0;
        for (int i = 0; i < size; i++)
        {
            temp.p[index] = p[i];
            index++;
        }

        for (int j = 0; j < obj.size; j++)
            temp.p[index++] = obj.p[j];

        return temp;
    }

    ~Vector()
    {
        delete[] p;
    }
};

int main()
{
    Vector v1(3), v2(5), v3;
    v1.getElements();
    v2.getElements();

    v1.diplayVector();
    v2.diplayVector();

    v3 = v1.createUnion(v2);
    cout << "Union: ";
    v3.diplayVector();

    return 0;
}