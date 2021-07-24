

/*
constt function and mutalbe keyword

also

const object can call the const functions only
while non-constt object can call both

*/

#include <iostream>
using namespace std;

class Base
{
    // int x;
    mutable int x;

public:
    Base() {}
    Base(int a) {}

    void SetX(int m) const
    {
        x = m;
        // 'Base::x' in read-only object
        // if mutalbe is not used else runs without error
    }
    int getX() { return x; }
};

int main()
{
    Base b;
    b.SetX(10);
    cout << b.getX() << endl;

    // see the const object
    const Base c;
    cout<<c.getX()<<endl; //error saying getX() is not constt function
    c.SetX(29); //ok since SetX() is const func() so callable by constt object
    return 0;
}