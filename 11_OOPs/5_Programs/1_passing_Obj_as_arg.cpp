
/*
shows the passing of an object as argument 
and avoid the function inlining by defining it outside
the class for that we've just have to tell to which
class our function belongs which is done using scope
resolution operator just before the function name

return_tyope className :: functionName(){ }
*/

#include <iostream>
using namespace std;

class complex
{
    int real, imag;

public:
    //will work as default constructor as well
    complex(int a = 0, int b = 0)
    {
        real = a;
        imag = b;

    } //this is inline function that too the constructor
    complex add(complex c1);
    void printInfo()
    {

        cout << real << " + " << imag << "i" << endl;
    }
};

//passing object as an argument
complex complex ::add(complex c1)
{
    complex temp;
    temp.real = real + c1.real;
    temp.imag = imag + c1.imag;

    return temp;
}

int main()
{
    complex c1(3, 4), c2(10, 2);

    complex c3;

    c3 = c1.add(c2);
    //note that this is not operator overloading
    cout << "object c1 is : ";
    c1.printInfo();
    cout << "object c2 is : ";
    c2.printInfo();
    cout << "object c3 is : ";
    c3.printInfo();
    return 0;
}