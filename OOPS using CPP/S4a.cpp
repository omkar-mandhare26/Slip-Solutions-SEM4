#include <iostream>
using namespace std;

class Worker
{
public:
    string name;
    int no_of_hrs, payRate, salary;

public:
    Worker(string Wname, int totalHrs, int pay = 500)
    {
        name = Wname;
        no_of_hrs = totalHrs;
        payRate = pay;
        salary = (no_of_hrs * 30) * payRate;
    }

    void displayDetails()
    {
        cout << "Worker Name: " << name << endl;
        cout << "No of Hours Worked: " << no_of_hrs << endl;
        cout << "Pay Rate: " << payRate << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main()
{
    string name;
    int totalHrs, payRate;

    cout << "Enter Worker's Name: ";
    cin >> name;

    cout << "Enter No of Hours Worked: ";
    cin >> totalHrs;

    cout << "Enter Pay Rate: ";
    cin >> payRate;

    Worker W(name, totalHrs, payRate);
    W.displayDetails();

    return 0;
}