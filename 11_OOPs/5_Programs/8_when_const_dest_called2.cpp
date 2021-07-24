/*
predict the order of print statement
========================

Test's constructor     
Test's copy constructor
Demo constructor  
*/

#include <iostream>
using namespace std;

class Test
{
public:
    Test() { cout << "Test's constructor" << endl; }

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
    Demo(Test &t) : T{t} //list assignment doesn't called Test const rather cretes T and calls copy const unlike previous one first createing T and then assigning
    {
        cout << "Demo constructor " << endl;
    }
};

int main()
{
    Test t1;
    Demo d1(t1);
    return 0;
}