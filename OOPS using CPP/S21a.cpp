#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_SIZE = 25;

class Employee
{
public:
    int empId, salary;
    char empName[MAX_SIZE], Cname[MAX_SIZE];

public:
    void getDetails()
    {
        cout << "Enter Employee ID: ";
        cin >> empId;
        cout << "Enter Employee Name: ";
        cin >> empName;
        cout << "Enter Company Name: ";
        cin >> Cname;
        cout << "Enter Salary: ";
        cin >> salary;
    }

    void displayDetails()
    {
        cout << "\nEmployee ID: " << empId << endl;
        cout << "\nEmployee Name: " << empName << endl;
        cout << "\nCompany Name: " << Cname << endl;
        cout << "\nSalary: " << setfill('*') << setw(7) << right << salary << endl;
    }
};

ostream &salaryFormat(ostream &output)
{
    output << setfill('$') << setw(10) << right;
    return output;
}

int main()
{
    Employee emp;
    emp.getDetails();

    cout << "\nEmployee Details: \n";
    emp.displayDetails();

    cout << "\nDiplaying Salary using user defined manipulator:\n";
    cout << salaryFormat << emp.salary;
    return 0;
}