#include <iostream>
using namespace std;

class student
{
    string name;

public:
    //data members
    int age;
    char gender;

    //normal fuctions
    string getName();
    void setName();
    void printInfo();

    student(string, int, char);
    //default constructor which does nothing
    //needed bcz both we are using parameterized
    //as well as non parameterized
    student()
    {
        cout << "default constructor is called" << endl;
    }
    //third type of constructor is copy constructor
    //preferred to pass by reference(to avoid non-terminating 
    //calling to itself bcz in pass by value new copies are passed) and also constt

    //One reason for passing const reference is, we should use 
    //const in C++ wherever possible so that objects are not accidentally modified.
    student(const student &a)
    {
        cout << "copy constructor called" << endl;
        name = a.name;
        age = a.age;
        gender = a.gender;
    }

    // destructor no return type,no parameters,no overloading of it

    ~student()
    {
        cout << "destructor called" << endl;
    }

    // operator overloading

    bool operator==(student &a);
};

//even for this also need to provide the prototype
student ::student(string s, int age, char gender)
{
    cout << "Parameterized constructor called" << endl;
    name = s;
    age = age;
    gender = gender;
}

void student ::setName()
{
    cin >> name;
}
string student ::getName()
{
    return name;
}

void student ::printInfo()
{
    cout << "name : " << name << endl;
    cout << "age : " << age << endl;
    cout << "gender : " << gender << endl;
}

// overloading the == operator

bool student ::operator==(student &a)
{
    if (name == a.name && age == a.age && gender == a.gender)
    {
        return true;
    }

    return false;
}

int main()
{
    student s[3];
    for (int i = 0; i < 3; i++)
    {
        cout << "name : ";
        s[i].setName();
        cout << "age : ";
        cin >> s[i].age;
        cout << "gender : ";
        cin >> s[i].gender;
    }

    cout << "\n--------------------\n";
    for (int i = 0; i < 3; i++)
    {
        s[i].printInfo();
    }
    // constructor
    student s1("Anand", 20, 'M');
    cout << s1.getName() << endl;

    //using the copy constructor
    student s2(s1); //using default copy construcor
    cout << s2.getName() << endl;

    student s3 = s2;
    // copy constructor would be called

    student s4; //(default constructor would be called)
    s4 = s2;
    //No  copy constructor would be called
    //rather compiler overload = operator
    //and perfom our task

    // operator overloading
    if (s4 == s2)
    {
        cout << "both are same" << endl;
    }
    return 0;
}