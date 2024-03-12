#include <iostream>
#include <cstring>
using namespace std;

class String
{
public:
    char str[50];

public:
    String(char *s)
    {
        strcpy(str, s);
    }

    void display()
    {
        cout << str << endl;
    }

    int replaceStr(char s1, char s2)
    {
        int i = 0, count = 0;
        while (str[i] != '\0')
        {
            if (str[i] == s1)
            {
                str[i] = s2;
                count++;
            }

            i++;
        }

        return count;
    }
};

int main()
{
    char s[] = {"Hello World"};
    String str(s);
    cout << "Initial String: ";
    str.display();

    cout << "String after replace: ";
    str.replaceStr('o', 'u');
    str.display();
    return 0;
}