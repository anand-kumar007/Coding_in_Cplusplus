/*
predict the order of print statement
========================

Test's constructor
Test's constructor
Test's assignment 
Demo constructor  
Test's destructor 
Test's destructor 

*/

#include <iostream>
using namespace std;

class Test
{
public:
    Test() { cout << "Test's constructor" << endl; }
    ~Test() { cout << "Test's destructor" << endl; }

    Test(const Test &obj)
    {
        cout << "Test's copy constructor" << endl;
    }

    Test &operator=(const Test &obj)
    {
        if (this == &obj)
            return *this;

        cout << "Test's assignment" << endl;
        return *this;
    }
};

class Demo
{
    Test T;

public:
    Demo(Test &t) //reference doesn't call the constructor
    {
        Demo::T = t; //second time Test constructor
        cout << "Demo constructor " << endl;
    }
};

int main()
{
    Test t1;
    Demo d1(t1);
    return 0;
}