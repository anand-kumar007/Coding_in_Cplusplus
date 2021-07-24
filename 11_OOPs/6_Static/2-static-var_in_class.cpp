

/*
Static keyword has different meanings when used with different types. 
We can use static keyword with:

Static Variables : Variables in a function, Variables in a class
Static Members of Class : Class objects and Functions in a class

Let us now look at each one of these use of static in details:
1. static variable in a function (the previous program)
2. stativ varible in class (here)
*/

// Static variables in a class: As the variables declared as static are initialized only once as they are allocated space in separate static storage so, the static variables in a class are shared by the objects. There can not be multiple copies of same static variables for different objects. Also because of this reason static variables can not be initialized using constructors.

#include <iostream>
using namespace std;

class ABC
{

public:
    static int i;
    ABC(){

    };
};

//this has to be done explicitly constructor cannot do that
//since only one copy is maintained !!! see the ouput

//everytime you use a static variable in class you gotta tell the
//compiler about it using this notation

int ABC::i = 0;

int main()
{
    ABC obj1;
    ABC obj2;

    obj1.i = 1;
    obj2.i = 3;

    cout << "obj1 i : " << obj1.i << endl;
    cout << "obj2 i : " << obj2.i << endl;

    return 1;
}

//obj1 i : 3
// obj2 i : 3

/*
You can see in the above program that we have tried 
to create multiple copies of the static variable i for multiple objects.

But this didn’t happen. So, a static variable inside a class should 
be initialized explicitly by the user using the class name 
and scope resolution operator outside the class as shown below:

int ABC::i = 10; etc
*/
