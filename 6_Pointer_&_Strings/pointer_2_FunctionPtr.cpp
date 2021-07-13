
#include<iostream>
using namespace std;

int add(int ,int);

int main()
{
    cout<<"address of main is : "<<&main<<endl;
    
    /* a function ptr point to a function
    with return type int and parameters(int,int)
    */
   int (*fptr) (int ,int) = NULL;
   
   fptr = add; //function name acts as pointer

   int sum = fptr(10,230);
   cout<<"sum is : "<<sum<<endl;

   cout<<"address of add function is : "<<fptr
       <<" "<<"and "<<&add<<endl; 

   return 0;
}

int add(int a, int b)
{
    return a+b;
}