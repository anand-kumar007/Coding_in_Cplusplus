/*
update the bit at required positon to 0 or 1 according to user's need
Procedure is
clear the bit at that position
set the bit now with value to be set
Done
*/

#include<iostream>
#define ULLI unsigned long long int
using namespace std;

ULLI DecimalToBinary(int num);

int ClearBit(int num,int pos)
{
    int mask = ~(1<<pos);
    
    return (num & mask) ;
}

int SetBit(int num, int pos)
{
    return (num | (1<<pos)) ;

}

int UpdateBit(int num, int pos, int value)
{
    num = ClearBit(num,pos);
    // setting the bit it own since a bit modified setting of bit 
    // is needed

    return (num | (value<<pos));
}

int main()
{
    int num;
    cout<<"enter the number : ";
    cin>>num;
    cout<<"Number is : "<<DecimalToBinary(num)<<endl;

    int pos,value;
    cout<<"enter the position and value to update : ";
    cin>>pos>>value;

    cout<<"Number after Updating the Bit : "<<DecimalToBinary(UpdateBit(num,pos,value));

    return 0; 

}

ULLI DecimalToBinary(int num)
{
    ULLI ans = 0;
    int x = 2; //base
    int quotient;

    while (x < num)
    {
        x *= 2;
    }
    x /= 2;

    while (x > 0)
    {
        quotient = num / x;
        num -= quotient * x;
        ans = ans * 10 + quotient;
        x /= 2;
    }

    return ans;
}