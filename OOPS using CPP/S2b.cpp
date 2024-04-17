#include <iostream>
#include <fstream>
using namespace std;

class movie
{
    int mid;
    char mname[20];
    char dname[15];
    int ryear;
    double bud;

public:
    void accept()
    {
        cout << "\nEnter the movie id: ";
        cin >> mid;
        cout << "Enter the movie name: ";
        cin >> mname;
        cout << "Enter the director name: ";
        cin >> dname;
        cout << "Enter the budget: ";
        cin >> bud;
        cout << "Enter the release year: ";
        cin >> ryear;
    }
    void display()
    {
        cout << "The movie id: " << mid << endl;
        cout << "The movie name: " << mname << endl;
        cout << "The director name: " << dname << endl;
        cout << "The movie budget: " << bud << endl;
        cout << "The movie release year: " << ryear << endl;
    }

    void insertFile(char *filename)
    {
        ofstream outfile(filename);
        outfile << "The movie id: " << mid << endl;
        outfile << "The movie name: " << mname << endl;
        outfile << "The director name: " << dname << endl;
        outfile << "The movie budget: " << bud << endl;
        outfile << "The movie release year: " << ryear << endl;
    }
};

int main()
{
    movie m[5];
    int n, i;
    char filename[] = {"S2b_movie.txt"};
    cout << "Enter the no of record you want: ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        m[i].accept();
        m[i].insertFile(filename);
    }
    cout << "\nDetails of movie from the file: ";

    ifstream infile;
    infile.open(filename);
    char c;
    while ((c = infile.get()) != EOF)
    {
        cout << c;
    }

    return 0;
}