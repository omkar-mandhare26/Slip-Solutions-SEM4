#include <iostream>
using namespace std;

class Employee
{
public:
    int empCode, salary;
    char *name;

public:
    void getEmpDetails()
    {
        cout << "Enter Employee Code: ";
        cin >> empCode;

        cout << "Enter Employee Name: ";
        cin >> name;
    }
};

class partTime;

class fullTime : public Employee
{
public:
    int dailyWages, no_of_days;

public:
    friend void maxSalary(fullTime *obj1, partTime *obj2, int n1, int n2);
    void getFTDetails()
    {
        Employee::getEmpDetails();
        cout << "Enter Daily Wages: ";
        cin >> dailyWages;

        cout << "Enter No of Days Worked: ";
        cin >> no_of_days;

        salary = dailyWages * no_of_days;
    }

    void displayDetails()
    {
        cout << "Employee Code: " << empCode << endl;
        cout << "Employee Name: " << name << endl;
        cout << "Employee Salary: " << salary << endl;
        cout << "Daily Wages: " << dailyWages << endl;
        cout << "No of Days Worked: " << no_of_days << "\n\n";
    }
};

class partTime : public Employee
{
public:
    int no_of_hrs, hourlyWages;

public:
    friend void maxSalary(fullTime *obj1, partTime *obj2, int n1, int n2);
    void getPTDetails()
    {
        Employee::getEmpDetails();
        cout << "Enter Hourly Wages: ";
        cin >> hourlyWages;

        cout << "Enter No of Hours Worked: ";
        cin >> no_of_hrs;

        salary = hourlyWages * no_of_hrs;
    }

    void displayDetails()
    {
        cout << "Employee Code: " << empCode << endl;
        cout << "Employee Name: " << name << endl;
        cout << "Employee Salary: " << salary << endl;
        cout << "Daily Wages: " << hourlyWages << endl;
        cout << "No of Days Worked: " << no_of_hrs << "\n\n";
    }
};
void maxSalary(fullTime *obj1, partTime *obj2, int n1, int n2)
{
    // 1,2,3,4,5

    int i, k;
    for (int max1 = obj1[0].salary, i = 1, k = 0; i < n1; i++)
    {
        if (max1 < obj1[i].salary)
        {
            max1 = obj1[i].salary;
            k = i;
        }
    }

    cout << "\nFullTime Employee having maximum salary:\n";
    obj1[k].displayDetails();

    for (int max2 = obj2[0].salary, i = 1, k = 0; i < n2; i++)
    {
        if (max2 < obj2[i].salary)
        {
            max2 = obj2[i].salary;
            k = i;
        }
    }

    cout << "\nPartTime Employee having maximum salary:\n";
    obj2[k].displayDetails();
}

int main()
{
    int n, ch, f = 0, p = 0;
    fullTime ft[20];
    partTime pt[20];
    do
    {
        cout << "\n1. Accept the details of N employees & Calculate Salary\n2. Display the details of N employees\n3. Display the details of employee having maximum salary\n4. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            int type;
            cout << "Enter Number of Employees: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "\nPress 1 for FullTime employee, 2 for PartTime Employee: ";
                cin >> type;
                if (type == 1)
                {
                    ft[f].getFTDetails();
                    f++;
                }
                else if (type == 2)
                {
                    pt[p].getPTDetails();
                    p++;
                }
            }
            break;
        case 2:
            cout << "\nFull Time Employees:\n";
            for (int i = 0; i < f; i++)
                ft[i].displayDetails();

            cout << "\nPart Time Employees:\n";
            for (int i = 0; i < p; i++)
                pt[i].displayDetails();
            break;
        case 3:
            maxSalary(ft, pt, f, p);
            break;
        case 4:
            exit(1);

        default:
            cout << "\nInvalid Choice\n";
        }
    } while (ch != 4);
    return 0;
}