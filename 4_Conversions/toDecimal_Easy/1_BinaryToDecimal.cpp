/*
=========================
1011 = 11
101101 = 45
=========================*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    unsigned int BNumber;
    cout<<"Enter Binary number : ";
    cin>>BNumber;

    int sum=0,i=0;
    while(BNumber >0)
    {
        int digit = BNumber%10;
        sum = sum + digit*pow(2,i);
        i++;

        BNumber /=10;
    }

    cout<<"Decimal form is : "<<sum;
    return 0;
}