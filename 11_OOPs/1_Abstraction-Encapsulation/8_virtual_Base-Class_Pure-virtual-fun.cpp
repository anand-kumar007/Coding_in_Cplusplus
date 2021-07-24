

/*
virtual base class is one which has pure virtual function

just add pure = 0 at end of the virtual function

virtual void display() = 0;

also called do nothing function

1. you need to define it in all derived classes
2. or make it pure virtual in derived class (either of two has to be done)

Vitual base class' object cannot be created put its pointer can be created

virtual base class is used to store the common data

*/

#include <iostream>
using namespace std;

class Database
{
public:
    virtual void getname() = 0;
};

class manager : public Database
{
public:
    void getname()
    {
        cout << "getting name of manager" << endl;
    }
};

class customer : public Database
{
public:
    void getname()
    {
        cout << "getting name of customer" << endl;
    }
};

class accountant : public Database
{
public:
    void getname()
    {
        cout << "getting name of accountant" << endl;
    }
};

int main()
{
    accountant a1;
    customer c1;
    manager m1;

    a1.getname();
    c1.getname();
    m1.getname();

    return 0;
}