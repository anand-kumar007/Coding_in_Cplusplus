/*
clearing the bit at a position means setting the bit to 0 
at that position
*/

#include<iostream>
#define ULLI unsigned long long int 
using namespace std;

ULLI DecimalToBinary(int num);
void ClearBit(int num, int pos);

int main()
{
    int num;
    cout<<"enter the number : ";
    cin>>num;
    cout<<"Number is : "<<DecimalToBinary(num)<<endl;

    int pos;
    cout<<"Enter the positon to set bit = 0 : ";
    cin>>pos;

    ClearBit(num,pos);

    return 0;
}

void ClearBit(int num, int pos)
{
    // make a variable with all bit 1 except @ required positon
    // 1<<pos and its ones complement to get required variable
    int variable = 1<<pos;
    variable = ~(variable);

    num = num & variable;


    cout<<"Number after clearing bit : "<<DecimalToBinary(num);
    return ;
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