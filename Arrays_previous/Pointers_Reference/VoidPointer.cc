#include <iostream>
using namespace std;

int main()
{
    void *ptr;
    float f = 10.11;

    // assign float address to void pointer
    ptr = &f;

    cout << "The content of pointer is ";
    // use type casting to print pointer content
    // cout << *(static_cast<float *>(ptr));

    //do the casting properly and then de-refernce it
    cout<<*((float *)ptr)<<endl;

    return 0;
}