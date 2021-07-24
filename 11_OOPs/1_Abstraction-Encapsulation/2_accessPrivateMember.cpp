/*
syntax and printing the data members of the class
-------------------
Name    Age     Rollno
anand   20      101
sam     21      102
siya    20      104

*/
#include <iostream>
using namespace std;
class student
{
    string name;

public:
    int age;
    string rollno;
    void printInfo();
    void setName(string st);
};

void student ::setName(string st)
{
    this->name = st;
    // name = st; both are same
}
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
        // s[i].setName();
        string st;
        cin >> st;
        s[i].setName(st);
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