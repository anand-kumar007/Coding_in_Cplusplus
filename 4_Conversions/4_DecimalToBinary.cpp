/*
=========================
11 = 1011  
45 = 101101
=========================*/

#include <iostream>
#include<cmath>
using namespace std;
#define ull unsigned long long int

ull DecimaltoBinary(int );
void RecursiveDtoB(int num);

    int main()
{
    
    int Num;
    cout << "Enter Decimal number : ";
    cin >> Num;

    //    RecursiveDtoB(Num);
    cout << "Binary form is : " << DecimaltoBinary(Num);
    return 0;
}

ull DecimaltoBinary(int num) 
{
    ull ans=0;
    int x = 1;  //base
    while(x <=num)
    {
        x *= 2;
    }
    x /=2;

    while(x > 0)
    {
        int quotient = num/x ;  //getting the quotient
        num = num - quotient*x;  //reducing the number by (quotient*x)

        x /=2;

        //compute the answer
        ans = ans*10 + quotient;

    }
    return ans;
}

void RecursiveDtoB(int num)
{
    if(num<=0)
    return ;
    RecursiveDtoB(num/2);
    cout<<num%2;
}