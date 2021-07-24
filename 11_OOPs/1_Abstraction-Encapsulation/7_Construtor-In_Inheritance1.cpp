
/*
when an object of derived class is created first the cosntructor
of base class is called 

//in case of default costructor compiler automatically adds :A()
part own its own
for parameterized constructor we need to pass the values of base class
constructor


B() : A()
{
    cout<<"derived class constructor"<<endl;
}


B(int a,int b) : A(b)
{
    B_data = a; //say
    cout<<"derived class constructor"<<endl;
}

*/
#include <iostream>
using namespace std;

class Base
{
protected:
    int Base_data;

public:
    Base()
    {
        cout << "base class constructor default one !!" << endl;
    }
    Base(int x)
    {
        Base_data = x;
    }
};

class Derived : public Base
{
    int Derived_data;

public:
    Derived()
    {
        cout << "derived class cosntructor default one !!" << endl;
    }
    Derived(int y, int x) : Base(x)
    {
        Derived_data = y;
    }

    void show()
    {
        cout << "Derived data : " << Derived_data << endl;
        cout << "Base data : " << Base_data << endl;
    }
};

int main()
{
    Derived d1;
    //run it

    // Derived(10); //will call base class' default constucotr
    // d.show(); // and will assign garbage values to both derive_data and base_data

    //Now define the Consturctor properly
    Derived d2(10, 5);
    d2.show();
    return 0;
}

// base class constructor default one !!
// derived class cosntructor default one !!
// Derived data : 10
// Base data : 5
