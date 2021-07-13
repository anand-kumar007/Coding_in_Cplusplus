/*
array name is a constt ptr to first element of it

hence ++,--,etc can be done on it unlike other
normal pointers

pointer are used to access RESOURCES(monitor,files,keyboard)
to access heap
to pass as parameter
*/

#include<iostream>
using namespace std;

int main()
{
    int a=10;
    int *aptr= &a;

    cout<<*aptr<<endl; //10

    *aptr = 20;
    cout<<a<<endl; //20

    int arr[]={10,20,30};
    cout<<*arr<<endl;  //10

    //cz arr is itself a ptr so No & needed
    int *ptr = arr;

    for(int i=0; i<3; i++)
    {
        cout<<*ptr<<" ";
        *ptr++;
        // cout << *arr << " ";
        // *arr++;// would throw an error
        // cout<<*(arr+i)<<" "; would work
    }

    //address of main function
    cout<<endl<<&main;       //1
    return 0; 
}