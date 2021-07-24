
/*
second way to avoid two copies of class A in D
is using the virtual class (during inheritance)

widely used method
*/

#include <iostream>
using namespace std;

class ClassA
{
public:
    int a;
};
              //note here
class ClassB : virtual public ClassA
{
public:
    int b;
};

              //note
class ClassC : virtual public ClassA
{
public:
    int c;
};

class ClassD : public ClassB, public ClassC
{
public:
    int d;
};

int main()
{

    ClassD obj;

    obj.a = 10;  //Statement 3
    obj.a = 100; //Statement 4 (simply overrdies the value of a)

    obj.b = 20;
    obj.c = 30;
    obj.d = 40;

    cout << "\n A : " << obj.a;
    cout << "\n B : " << obj.b;
    cout << "\n C : " << obj.c;
    cout << "\n D : " << obj.d;
}
