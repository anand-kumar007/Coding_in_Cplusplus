/*
instead of taking input from user
or assigning them after creating object
what if we could initialize the values 
of data member for particular object
when that object is create
----------------------
constructor comes to rescue here !!

default() ---> default constructor
user_define(args) -> parameterized
copy_constructor() ---> copy cosntructor


========================================
When is  copy constructor called? 
In C++, a Copy Constructor may be called in the following cases: 
1. When an object of the class is returned by value. 
2. When an object of the class is passed (to a function) by value as an argument. 
3. When an object is constructed based on another object of the same class. 
4. When the compiler generates a temporary object.

It is, however, not guaranteed that a copy constructor will be 
called in all these cases, because the C++ Standard allows 
the compiler to optimize the copy away in certain cases, 
one example is the return value optimization (sometimes referred to as RVO).
=====================================================
Can we make copy constructor private? 

Yes, a copy constructor can be made private. 
When we make a copy constructor private in a class, 
objects of that class become non-copyable. 
This is particularly useful when our class has pointers 
or dynamically allocated resources. In such situations, 
we can either write our own copy constructor like above 
String example or make a private copy constructor so 
that users get compiler errors rather than surprises at runtime. 

=======================================================
Why argument to a copy constructor must be passed as a reference? 

A copy constructor is called when an object is passed by value. 
Copy constructor itself is a function. So if we pass an argument 
by value in a copy constructor, a call to copy constructor would 
be made to call copy constructor which becomes a non-terminating 
chain of calls. 

Therefore compiler doesn’t allow parameters to be passed by value.

*/

#include <iostream>
using namespace std;

class student
{
    string name;

public:
    int age;
    string rollno;
    void setName(string st);
    void printInfo();
    string getName();

    /* -------- constructors ------*/
    student(string, int, string); //user define
    student()
    {
        cout << "Default constructor called" << endl;
    } //default

    student(student &s); //copy constructor(must be passed as address)

    //destuructor
    ~student()
    {
        cout << "destrucotr called" << endl;
    }
};

void student ::setName(string st)
{
    this->name = st;
}

string student ::getName()
{
    return this->name;
}

void student ::printInfo()
{
    cout << name << "\t" << age << "\t" << rollno << endl;
}

/* ----------- constructors ------------ */

//parameterized (user defined obviously)
student ::student(string str, int num, string rStr)
{
    cout << "cosntructor called !!" << endl;
    this->name = str;
    this->age = num;
    this->rollno = rStr;
}

//copy constructor
student ::student(student &s)
{
    cout << "copy constructor called !" << endl;
    this->name = s.name;
    this->age = s.age;
    this->rollno = s.rollno;
}

int main()
{
    student a1("Rashi", 19, "191IT201");
    student a2("Radha", 18, "191IT190");
    student a3 = a1; //copy constructor called

    student a4(a1); //copy constructor called
    a4 = a2;        //no copy constructor called but values are copied

    //manually call the destructor for a4 lets say
    a4.~student();

    cout << "-----------------\n";
    cout << "Name\tage\trollno\n";
    a1.printInfo();
    a2.printInfo();
    a3.printInfo();
    a4.printInfo(); //still able to use a4 (How !!)

    return 0;
}

/*
__________________CONSTRUCTOR_____________________

if you don't define a copy constructor
it would use the inbuilt one which perfomrs shallow copying
(so in case our data memebers includes pointers) we have
to define our own.

constructor
no return value ,can be overloaded

destrucotr
no return or parameters, can't be overloaded

*/

/*
______________________DESTRUCTOR________________
A destructor is a special member function that 
is called when the lifetime of an object ends. 
The purpose of the destructor is to free the 
resources that the object may have acquired during its lifetime.

If no user-declared prospective (since C++20)destructor is 
provided for a class type (struct, class, or union), 
the compiler will always declare a destructor 
as an inline public member of its class.
___________________________________________________________________________
The destructor is called whenever an object's lifetime ends, which includes
____________________________________________________________________________
1) program termination, for objects with static storage duration
2) thread exit, for objects with thread-local storage duration (since C++11)
3) end of scope, for objects with automatic storage duration and for temporaries 
   whose life was extended by binding to a reference
4) delete-expression, for objects with dynamic storage duration (((((IMPORTANT))))
5) end of the full expression, for nameless temporaries

______________Did manually calling the destructor fail to destroy the object?______________

 I think that the destructor causes the object to be destroyed, 
 so it no longer exists in the memory. After I explicitly call the destructor, 
 I should be no longer able to use that object again, since it is destroyed. 
 However, I am able to call a function of the object and 
 print the value of the internal data member. 
 Did manually calling the destructor fail to destroy the object? 
 
 What's going on here?

" Note that calling a destructor directly for an ordinary object, 
such as a local variable, invokes undefined behavior 
when the destructor is called again, at the end of scope." 

The ONLY time you can safely call a destructor MANUALLY is 
when the object is constructed using placement-new, 
which is not the case in any of your examples. 
If you want deterministic control over when an object is destroyed, 
put it in a scope that you control, or use new/delete (or smart wrappers). 
But either way, once an object has been destructed, i
t is not safe to access its members anymore.


 */