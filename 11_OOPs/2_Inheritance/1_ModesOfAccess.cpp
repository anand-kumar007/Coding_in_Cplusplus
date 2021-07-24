// C++ Implementation to show that a derived class
// doesn’t inherit access to private data members.
// However, it does inherit a full parent object

#include <iostream>
using namespace std;

class A
{
public:
    int x;

protected:
    int y;

private:
    int z;
};

class B : public A
{
    // x is public
    // y is protected
    // z is not accessible from B
};

class C : protected A
{
    // x is protected
    // y is protected
    // z is not accessible from C
};

class D : private A // 'private' is default for classes
{
    // x is private
    // y is private
    // z is not accessible from D
};

int main()
{

    return 0;
}

/*

Modes of Inheritance

Public mode: 

If we derive a sub class from a public base class. 
Then the public member of the base class will become 
public in the derived class and protected members of 
the base class will become protected in derived class.

Protected mode: 

If we derive a sub class from a Protected base class. 
Then both public member and protected members 
of the base class will become protected in derived class.

Private mode:

If we derive a sub class from a Private base class.
Then both public member and protected members of the 
base class will become Private in derived class. 

*/