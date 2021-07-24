/*
A derived class with two base classes and these two base classes 
have one common base class is called multipath inheritance.
An ambiguity can arrise in this type of inheritance. 

*/

// C++ program demonstrating ambiguity in Multipath
// Inheritance

#include <conio.h>
#include <iostream>
using namespace std;

class ClassA
{
public:
    int a;
};

class ClassB : public ClassA
{
public:
    int b;
};
class ClassC : public ClassA
{
public:
    int c;
};

class ClassD : public ClassB, public ClassC
{
public:
    int d;
};

void main()
{

    ClassD obj;

    // obj.a = 10;				 //Statement 1, Error
    // obj.a = 100;				 //Statement 2, Error

    obj.ClassB::a = 10;  // Statement 3
    obj.ClassC::a = 100; // Statement 4

    obj.b = 20;
    obj.c = 30;
    obj.d = 40;

    cout << "\n A from ClassB : " << obj.ClassB::a;
    cout << "\n A from ClassC : " << obj.ClassC::a;

    cout << "\n B : " << obj.b;
    cout << "\n C : " << obj.c;
    cout << "\n D : " << obj.d;
}


/*
In the above example, both ClassB & ClassC inherit ClassA, they both have single copy of ClassA. However ClassD inherit both ClassB & ClassC, therefore ClassD have two copies of ClassA, one from ClassB and another from ClassC. 

If we need to access the data member a of ClassA through the object of ClassD, we must specify the path from which a will be accessed, whether it is from ClassB or ClassC, bco’z compiler can’t differentiate between two copies of ClassA in ClassD.

There are 2 ways to avoid this ambiguity: 

1.using scope resolution 
obj.ClassB::a = 10;        //Statement 3
obj.ClassC::a = 100;      //Statement 4

---
Note : Still, there are two copies of ClassA in ClassD.

2.virtual class
No two copies of A in D

*/
