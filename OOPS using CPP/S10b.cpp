#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

void heading();

class City
{
public:
    int cityCode, population;
    char cityName[15];

public:
    City() {}

    void getDetails()
    {
        cout << "\nEnter City Code: ";
        cin >> cityCode;
        cout << "Enter City Name: ";
        cin >> cityName;
        cout << "Enter City Population: ";
        cin >> population;
    }

    void displayDetails()
    {
        cout << left << setw(15) << cityCode << left << setw(15) << cityName << left << setw(15) << population << endl;
    }

    void sortObj(City obj1, City obj2)
    {
        if (obj1.population > obj2.population)
        {
            City temp = obj1;
            obj1 = obj2;
            obj2 = temp;
        }
    }
};

int main()
{
    int n, i;
    cout << "Enter Number of Cities: ";
    cin >> n;

    City *c = new City[n];
    for (i = 0; i < n; i++)
        c[i].getDetails();

    int ch;
    do
    {
        cout << "\n\n1. Display Cities\n2. Display Cities in Ascending Order\n3. Display Details of a Particular City\n4. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "City Details: \n";
            heading();
            for (i = 0; i < n; i++)
                c[i].displayDetails();
            break;
        case 2:
            cout << "City Details in Ascending Order:\n";
            heading();
            for (i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                    c[i].sortObj(c[i], c[j]);
                c[i].displayDetails();
            }
            break;
        case 3:
            char cityname[10];
            cout << "Enter City Name to Display Details: ";
            cin >> cityname;

            for (i = 0; i < n; i++)
                if (strcmp(cityname, c[i].cityName) == 0)
                {
                    heading();
                    c[i].displayDetails();
                }
            break;
        case 4:
            exit(1);

        default:
            cout << "Invalid Choice";
        }
    } while (ch != 4);

    return 0;
}

void heading()
{
    cout << left << setw(15) << "Code" << left << setw(15) << "Name" << left << setw(15) << "Population" << endl;
}