/*
sizeof classes in case of inheritance
*/

#include <iostream>
using namespace std;

class A
{
    int arr[10];
};

class B : public A
{
};

class C : public A
{
};

// class D : public B, public C {
// };
class D : virtual public B, virtual public C
{
};

int main()
{
    cout << sizeof(D) << endl; //without virtual inheritance 80 with virtual inheritance 84
    return 0;
}

/*
bcz a virtual keyword is used then it creates virtual table with virtual pointer

vptr is 4 bytes and similarly arr[10] is of size 40

during copy only one 40 is copied and one vptr size so
that makes size 84

*/