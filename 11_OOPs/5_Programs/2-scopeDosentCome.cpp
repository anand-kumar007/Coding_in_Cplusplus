#include <iostream>
using namespace std;

class A
{
public:
     float add(int a) { return a + 0.1; };
    // virtual float add(int a) { return a + 0.1; };
};

class B : public A
{
public:
    using A::add; //will bring the scope as well
    int add(int a) { return a + 10; }
};
int main()
{
    // B obj;
    // int num1 = obj.add(10);
    // int num2 = obj.add(10.5);
    // cout << num1 << endl
    //      << num2 << endl;

    return 0;
}

//20
//20
/*
the reason being though the function add is inherited
it's scope doesn't come so you can't call it this way!!

*/