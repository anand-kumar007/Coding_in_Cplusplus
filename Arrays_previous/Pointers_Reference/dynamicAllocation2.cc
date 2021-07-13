#include<iostream>
using namespace std;

int main()
{
    int num;
    float* ptr;
    cout<<"Enter the total Numbers : ";
    cin>>num;

    ptr = new float[num];
    //take the array input

    cout<<"Enter "<<num<<" elements : "<<endl;
    for(int i=0; i<num; i++)
    cin>>*(ptr+i);

    //output the array

    cout<<"\nElements are : ";
    for(int i=0; i<num; i++)
    cout<<*(ptr+i)<<" ";

    delete [] ptr;

    return 0;
}