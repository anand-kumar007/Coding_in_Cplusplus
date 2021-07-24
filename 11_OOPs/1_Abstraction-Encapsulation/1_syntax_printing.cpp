/*
syntax and printing the data members of the class
-------------------
Name    Age     Rollno
anand   19      110
sam     20      100
lisa    21      121

*/
#include <iostream>
using namespace std;
class student
{
public:
    string name;
    int age;
    string rollno;
    void printInfo();
};

void student ::printInfo()
{
    cout << name << "\t" << age << "\t" << rollno << endl;
}

int main()
{
    student s[3];
    for (int i = 0; i < 3; i++)
    {
        cout << "enter name,age,rollNo for student " << i << " : " << endl;
        cin >> s[i].name;
        cin >> s[i].age;
        cin >> s[i].rollno;
    }

    cout << "-------------------\n";
    cout << "Name\tAge\tRollno\n";
    for (int i = 0; i < 3; i++)
    {

        s[i].printInfo();
    }

    return 0;
}