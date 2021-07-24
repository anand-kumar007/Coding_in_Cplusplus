// Hierarchical Inheritance
// more than one sub class is inherited from a single base class.

#include <iostream>
using namespace std;

// base class
class Vehicle
{
public:
    Vehicle()
    {
        cout << "This is a Vehicle" << endl;
    }
};

// first sub class
class Car : public Vehicle
{
};

// second sub class
class Bus : public Vehicle
{
};

 
int main()
{
    // creating object of sub class will
    // invoke the constructor of base class
    Car obj1;
    Bus obj2;
    return 0;
}
