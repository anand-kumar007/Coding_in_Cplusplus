#include<iostream>
using namespace std;
#define ull unsigned long long

ull factorial(int );

int main()
{
    int num;
    cout<<"enter num ";
    cin>>num;

    cout<<num<<"! = "<<factorial(num);
}

ull factorial(int num)
{
    ull fact = 1;
    for(int i=num; i>=1; i--)
    {
        fact *= i;

    }

    return fact;
}

/*
we will discuss the unsigned long long int data type in C++. 
It is the largest (64 bit) integer data type in C++. ... 
It takes a size of 64 bits. A maximum integer value that can 
be stored in an unsigned long long int data type is 
18, 446, 744, 073, 709, 551, 615, around 264 – 1(but is compiler dependent).
*/