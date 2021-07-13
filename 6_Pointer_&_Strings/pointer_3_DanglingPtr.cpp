/*
  we will see the alloction of memory in free store(heap) whose 
  size can be expanded as long as our virtual memory not like stack whose
  size is fixed so for programs which needs greater memory we'll use heap memory

  we can allocate the memory in heap using new operator(calls constructor )
  and returns ptr of same type (unlike malloc which returns void and doesn't calls constructor
  and because of this constructor calling new is faster than malloc function)

  to access the allocated memory in heap we need a ptr in stack which can point to 
  that memory location in heap
*/

#include<iostream>
using namespace std;

int main()
{
    int a=10; //allocate memory in stack
    // int *ptr = new int();  //allocte memory in heap
    int *ptr = new (nothrow) int;
    if (!ptr)
    {
      cout << "Memory allocation failed\n";
      return 0;
    }

    *ptr = 100;

    delete ptr; // now the ptr is dangling pointer 

    // beacause the memory pointed by ptr is freed and it is still pointing 
    // to that memory location

    //lets reuse it

    ptr = new int[4];
    //points to an array of 4 integers allocate in heap
    delete[] ptr; //again ptr is dangling ptr now
    // delete[4] ptr; //size is optional to put in [4]

    ptr = NULL; //no more dangling ptr

    return 0;
}

/*
we are insisting on memory deallocation bcz if do not free it and we  lost
the address pointing to that memory then it can not be used at all

memory leak condition. 

it should be avoided for programs like servers which doesn't terminates
very often then it is a severe condition.
*/

/*
If enough memory is not available in the heap to allocate, the new request 
indicates failure by throwing an exception of type std::bad_alloc, 

unless “nothrow” is used with the new operator, in which case it returns a 
NULL pointer. 

Therefore, it may be good idea to check for the pointer variable produced by 
new before using it program.

int *p = new(nothrow) int;
if (!p)
{
 cout << "Memory allocation failed\n";
}
*/