#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class myfile
{
public:
    char str[100];

public:
    myfile() {}
    myfile(char *str)
    {
        strcpy(this->str, str);
    }

    void display() { cout << "Str: " << str << endl; }

    myfile operator+(const myfile &obj)
    {
        myfile temp;
        strcpy(temp.str, str);
        strcat(temp.str, obj.str);

        return temp;
    }

    void operator!()
    {
        for (int i = 0; i < strlen(str); i++)
        {
            if (isupper(str[i]))
                str[i] = tolower(str[i]);
            else if (islower(str[i]))
                str[i] = toupper(str[i]);
        }
    }
};

int main()
{
    char str1[] = "Hello, this is string1";
    char str2[] = "Hello, this is string2";
    myfile obj1(str1), obj2(str2);

    myfile obj3 = obj1 + obj2;

    obj3.display();
    !obj3;
    obj3.display();
    return 0;
}
