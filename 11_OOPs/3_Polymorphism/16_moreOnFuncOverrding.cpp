
// calling the base class method using derived class object
/*
1. using scope resolution
2. using casting

all these methods leads to static binding

NOTE : dymanic/runtime  binding happend only when virtual keyword is used
       and we call the derived class method from Base class pointer

also note that base class ptr can point to derived class but not vice versa
*/
#include <iostream>
using namespace std;

class Base {
    public:
    void fun()
    {
        cout << "Base" << endl;
    }
};

class Derived : public Base 
{
    public :
    void fun()
    {
        cout << "derived" << endl;
    }
};

int main()
{
    Derived d;

    d.fun(); //drived class fun
    d.Base::fun();   //will call base class fun
    return 0;
}

/*
though it is function overidding
and compiler gets confused at first then it resolves
using the object prefernce whose fun() is to be called

*/