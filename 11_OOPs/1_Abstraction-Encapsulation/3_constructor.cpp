/*
instead of taking input from user
or assigning them after creating object
what if we could initialize the values 
of data member for particular object
when that object is create
----------------------
constructor comes to rescue here !!

default()
user_define() -> parameterized


=======================
cosntructor called !!
cosntructor called !!
Default constructor called
-----------------
Name    age     rollno
Rashi   19      191IT201
Radha   18      191IT190
Bob     0       -

*/

#include <iostream>
using namespace std;

class student
{
    string name;

public:
    int age;
    string rollno;
    void setName(string st);
    void printInfo();
    string getName();

    /* -------- constructors ------*/
    student(string, int, string);
    student()
    {
        cout << "Default constructor called" << endl;
    }
};

void student ::setName(string st)
{
    this->name = st;
}

string student ::getName()
{
    return this->name;
}

void student ::printInfo()
{
    cout << name << "\t" << age << "\t" << rollno << endl;
}

/* ----------- constructors ------------ */

student ::student(string str, int num, string rStr)
{
    cout << "cosntructor called !!" << endl;
    this->name = str;
    this->age = num;
    this->rollno = rStr;
}
int main()
{
    student a1("Rashi", 19, "191IT201");
    student a2("Radha", 18, "191IT190");
    student a3;

    a3.setName("Bob");
    a3.age = 0;
    a3.rollno = "-";
    cout << "-----------------\n";
    cout << "Name\tage\trollno\n";
    a1.printInfo();
    a2.printInfo();
    a3.printInfo();

    return 0;
}

/*
if we define a constructor and somehow need to use
default initialized then it throws an error
and we have to define a default constructor as well

*/