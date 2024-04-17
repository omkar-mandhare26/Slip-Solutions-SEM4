#include <iostream>
#include <cstring>
using namespace std;

class VisitingStaff
{
public:
    int workingHrs, salary, noSubs;
    char name[10], **subName;

public:
    VisitingStaff() {}
    VisitingStaff(char *Sname, int hrs, int subs, char *subnames[])
    {
        strcpy(name, Sname);
        noSubs = subs;
        workingHrs = hrs;
        salary = workingHrs * 300;

        subName = new char *[noSubs];
        for (int i = 0; i < noSubs; i++)
        {
            subName[i] = new char[10];
            strcpy(subName[i], subnames[i]);
        }
    }

    void display()
    {
        cout << "Staff Name: " << name << endl;
        cout << "Working Hours: " << workingHrs << endl;
        cout << "Salary: " << salary << endl;
        cout << "No of Subjects: " << noSubs << endl;
        cout << "Subject Names: ";
        for (int i = 0; i < noSubs; i++)
        {
            cout << subName[i];
            if (i < noSubs - 1)
                cout << ", ";
        }
    }
};

int main()
{
    char *subnames[] = {"DSA", "OOPS", "Node JS"};
    VisitingStaff staff("Rekha", 2, 3, subnames);
    staff.display();

    return 0;
}