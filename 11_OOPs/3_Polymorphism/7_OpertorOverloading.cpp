/*
In C++, we can make operators to work for user defined classes. 
This means C++ has the ability to provide the operators with a 
special meaning for a data type, this ability is known as 
operator overloading.

Its declaration is like  copy contructor except
it has return type as class 
function name = operator OPsymbol(+,- ,etc)

className operator + (className &obj)
___________________________________
almost all operator can be overloaded except

    . (dot) 
   :: (scope resolution)
   ?: (ternary)
      sizeof 
_____________________________   
*/

#include <iostream>
using namespace std;

class Complex
{

    int real, imag;

public:
    Complex(int r = 0, int i = 0)
    {
        real = r;
        imag = i;
    }

    // This is automatically called when '+' is used with
    // between two Complex objects
    Complex operator+(Complex &c);
    Complex operator-(Complex &c);
    void print() { cout << real << " + i" << imag << endl; }
};

Complex Complex ::operator+(Complex &c)
{
    Complex result;

    result.imag = imag + c.imag;
    result.real = real + c.real;

    return result;
}

Complex Complex ::operator-(Complex &c)
{
    Complex res;
    res.imag = imag - c.imag;
    res.real = real - c.real;

    return res;
}
int main()
{
    Complex c1(10, 5), c2(2, 4);
    Complex c3 = c1 + c2; // An example call to "operator+"

    cout << "c1 : ";
    c1.print();
    cout << "c2 : ";
    c2.print();

    cout << "c1 + c2 : ";
    c3.print();

    c3 = c1 - c2;
    cout << "c1 - c2 : ";
    c3.print();
}

/*
What is the difference between operator functions and normal functions?

Operator functions are same as normal functions. 
The only differences are, name of an operator function is always 
operator keyword followed by symbol of operator and operator 
functions are called when the corresponding operator is used.

*/