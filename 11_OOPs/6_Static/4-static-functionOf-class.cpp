
/*
Static functions in a class: 

Just like the static data members or static variables inside the class, static member functions also does not depend on object of class. 

We are allowed to invoke a static member function using the object and the ‘.’ operator but it is recommended to invoke the static members using the class name and the scope resolution operator.

Static member functions are allowed to access only the static data members or other static member functions, they can not access the non-static data members or member functions of the class.

*/

//like static function can access static members of class and other static function
// and static items are specific to class not to the object

//but not vice versa
//nonstatic method can access static members

#include <iostream>
using namespace std;

class ABC
{
    int a;
    static float x;

public:
    ABC()
    {
        a = 10;
    }
    void printNonStatic()
    {
        cout << "non-static " << a << endl;
        cout << "static " << x << endl;
    }
    static void printStatic()
    {
        // cout << "non-static " << a<<endl; //error
        cout << "static " << x << endl;
    }
};

float ABC::x = 2.3;

int main()
{
    ABC obj1;

    obj1.printNonStatic();
    cout << "static function" << endl;
    // obj1.printStatic();//allowed but recommended to use :: for calling static function

    ABC::printStatic();
    return 0;
}

/*
a static member function of a class cannot be virtual. 
a static member function of a class cannot be const. 
a static member function of a class cannot be volatile. 
      static void fun() const { } 
        //error
*/