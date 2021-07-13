/* 
Given a number task is to check if the number
is some power of 2 or not.
eg: 16,8,4,32,64,128 are power of 2
while 6,10,12 etc are not
*/
#include <iostream>
using namespace std;

//O(N) complexity soln
int checkPowerOf2(int n);

//O(1) time complexity soln
int checkPowerOf2UsingBit(int n)
{
    //for just one base case of n==0 so for that take && with n
    //taking && with n
    return (n && (n & (n-1) )== 0);
}

int main()
{
    int n;
    cout<<"Enter a Number : ";
    cin>>n;
    cout<<"using bit manipulation : "<<checkPowerOf2UsingBit(n)<<endl;

    if (checkPowerOf2(n))
        cout << "yes it is " << endl;
    else 
    cout<<"no it is not"<<endl;

    return 0;
}


int checkPowerOf2(int n)
{
    //find highest power of 2 corrsponding 
    //to that number and then check the remainder
    int highestPower=1;
    while(highestPower <= n)
    {
        highestPower *=2;
    }
    highestPower /=2;

    if(n%highestPower == 0)
    return 1;
    else 
    return 0;
    
}

/*
idea here is that all power of 2 are of the form
100,1000,10000,so on .....

so n & (n-1) will give 0 if they are power of 2 else 
it will give some other number.

and this is because 
6 = 0110
5 = 0101
means from n we can obtain n-1 by flipping the bits
on rightmost side starting from first set bit on the right 
hand side

if we take & of them we will get all bits same except
all the bits of rightmost side will be zero bcz all those
are just flipped form of each other and will give & result 
to zero.

In case of power of 2 numbers rightmost bit comes at the end
so n-1 will have 011111111... of the form and hence will give
0 on performing & with the n-1. 

*/