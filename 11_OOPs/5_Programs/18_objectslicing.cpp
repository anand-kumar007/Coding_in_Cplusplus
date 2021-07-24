
/*
Object slicing

since base doesnot know about all items of derived class
so if you make an assignment of derive to base object
object slicing happens

means only that part is assigned which is there in the 
base class
*/

#include <iostream>
using namespace std;

class A
{
    int x;
};

class B : public A
{
    int y;
};

int main()
{
    B b;
    A a = b;
    //object slicing will take place
    return 0;
}