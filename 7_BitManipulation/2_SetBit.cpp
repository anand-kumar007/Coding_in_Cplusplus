/*
Given a number and you are supposed to 
set the bit at particual positon of that number to
1 
*/

#include<iostream>
#define ULLI unsigned long long int
using namespace std;

void SetBit(int num,int pos);
ULLI DecimalToBinary(int num);

int main()
{
    int num;
    cout<<"enter a number : ";
    cin>>num;
    cout<<"Binary form of Number is : ";
    cout<<DecimalToBinary(num)<<endl;

    int pos,bit;
    cout<<"enter the position to set bit = 1 : ";
    cin>>pos;

    SetBit(num,pos);

    return 0;

}


void SetBit(int num, int pos)
{
    //make a variable with bit at required pos 1 and all other 0
    // ex: pos=3
    // variable = 1000 (1<<3) that is by Left shifting the 1 to those many positions

    //take OR of that with number it will set your bit
    //bcz on taking OR with such number which has 0 at all other positions
    //will not affect its other bits

    num = num | (1<<pos);

    cout<<"Numer after setting the bit is : "<<DecimalToBinary(num)<<endl;

}

ULLI DecimalToBinary(int num)
{
    ULLI ans=0;
    int x=2; //base
    int quotient;

    while(x<num)
    {
        x *=2;
    }
    x /=2;

    while(x>0)
    {
        quotient = num/x;
        num -= quotient*x;
        ans = ans*10 + quotient;
        x /=2;

    }

       return ans;
}