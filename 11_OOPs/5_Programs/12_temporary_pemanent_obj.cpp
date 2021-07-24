
#include <iostream>
using namespace std;

class A
{
public:
    A() { cout << "A()" << endl; }
    A(int x) { cout << "A(int x)" << endl; }
    ~A() { cout << "~A()" << endl; }
};

int main()
{
    A(); //in same line const and dest is called for temp obj
    A(2);
    // A()
    // ~A()
    // A(int x)
    // ~A()

    //else make permanent usual obj

    return 0;
}

