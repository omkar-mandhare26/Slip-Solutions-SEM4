#include <iostream>
#include <cstring>
using namespace std;

class Account
{
public:
    int accNo;
    float balance;
    char accType[10];

public:
    void getDetails()
    {
        cout << "Enter Account No, Balance, Type(Saving/Current): ";
        cin >> accNo >> balance;
        cin.ignore();
        cin.getline(accType, 10);
    }

    void displayDetails()
    {
        cout << "Account No: " << accNo << endl;
        cout << "Account Balance: " << balance << endl;
        cout << "Account Type: " << accType << "\n\n";
    }
};

int main()
{
    int n;
    cout << "Enter No of Accounts: ";
    cin >> n;

    Account *acc = new Account[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter Details for Acc " << i + 1 << endl;
        acc[i].getDetails();
    }

    for (int i = 0; i < n; i++)
    {
        cout << "\nDisplay Details for Acc " << i + 1 << endl;
        acc[i].displayDetails();
    }

    delete[] acc;

    return 0;
}