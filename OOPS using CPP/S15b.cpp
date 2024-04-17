#include <iostream>
#include <cstring>
using namespace std;
const int MAX_SIZE = 20;

class Seller
{
public:
    int Sqty, Tqty, commission;
    char Sname[MAX_SIZE], Pname[MAX_SIZE], month[MAX_SIZE];

public:
    void getDetails()
    {
        cout << "\nEnter Seller Name: ";
        cin >> Sname;
        cout << "Enter Product Name: ";
        cin >> Pname;
        cout << "Enter Month: ";
        cin >> month;
        cout << "Sales Made: ";
        cin >> Sqty;
        cout << "Enter Target: ";
        cin >> Tqty;

        if (Sqty >= Tqty)
        {
            cout << "Enter Commission per sale made: ";
            cin >> commission;
        }
    }

    void display()
    {
        cout << "\nSeller Name: " << Sname << endl;
        cout << "Product Name: " << Pname << endl;
        cout << "Sales made: " << Sqty << endl;
        cout << "Target Qty: " << Tqty << endl;

        if (Sqty < Tqty)
            cout << "No Commission";
        else if (Sqty == Tqty)
        {
            commission += (Tqty * commission) * 0.1;
            cout << "Commission: " << commission;
        }
        else if (Sqty > Tqty)
        {
            int salesComm = ((Sqty - Tqty) * commission) * 0.25;
            int targetComm = Tqty * 0.1;
            commission += salesComm;
        }
        cout << endl;
    }
};

int main()
{
    int i, n = 3;
    Seller salesperson[3];

    for (i = 0; i < n; i++)
        salesperson[i].getDetails();

    cout << "Seller Details: \n";
    for (i = 0; i < n; i++)
        salesperson[i].display();

    return 0;
}