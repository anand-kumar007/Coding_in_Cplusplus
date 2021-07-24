
/*

overloading new and delete

new --> first allocate required memory then calls the constructor
delete --> destrucot first then deallocate

*/

#include <iostream>
#include <stdio.h>

using namespace std;

class Test
{
public:
    Test() { cout << "Constructor called !!" << endl; }
    ~Test() { cout << "Destructor called !!" << endl; }

    void *operator new(size_t sizeOfObj)
    {
        cout << "New operator called" << endl;
        void *storage = malloc(sizeOfObj);
        return storage;
    }

    void operator delete(void *p)
    {
        cout << "delete operator called " << endl;
        free(p);
    }
};

int main()
{
    Test *t1 = new Test();
    delete t1;
    return 0;
}

/*

New operator called
Constructor called !!
Destructor called !!
delete operator called

*/