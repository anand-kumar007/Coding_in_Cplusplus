

/*
    characteristics of friend functions

1. Not in scope of class
2. called directly not like member functions
3. can be defined anywhere like private,public doesn't matter
4. need to pass object as argument to accss the private data using
    dot notation.
*/

#include <iostream>
using namespace std;

class Test
{
    int data1, data2;

public:
    Test(int a = 0, int b = 0)
    {
        data1 = a;
        data2 = b;
    }
    void display();
    friend void multiply(Test);
};

//definitions

void multiply(Test t1)
{
    int res = t1.data1 * t1.data2;

    cout << "multiplication : " << res << endl;
}

//scope resoution tells it is in the scope of the class
//the normal member function
void Test ::display()
{
    cout << "data1 : " << data1 << endl;
    cout << "data2 : " << data2 << endl;
}

int main()
{
    Test obj(10, 20);

    obj.display();

    //calling the friend function
    multiply(obj);

    return 0;
}

/*

Following are some important points about friend functions and classes: 
1) Friends should be used only for limited purpose. too many functions or external classes are declared as friends of a class with protected or private data, it lessens the value of encapsulation of separate classes in object-oriented programming.
2) Friendship is not mutual. If class A is a friend of B, then B doesn’t become a friend of A automatically.
3) Friendship is not inherited (See this for more details)
4) The concept of friends is not there in Java. 
*/