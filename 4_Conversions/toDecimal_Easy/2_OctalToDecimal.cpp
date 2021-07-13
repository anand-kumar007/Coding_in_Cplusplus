/*

Enter Octal Number : 127
Decimal Number is : 87

Enter Octal Number : 742
Decimal Number is : 482

*/
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int OctNum ;
    cout<<"Enter Octal Number : ";
    cin>>OctNum;

    int DecNum =0,i=0;
    int digit =0;
    while(OctNum>0)
    {
        digit = OctNum % 10;
        DecNum += digit* pow(8,i);
        i++;
        OctNum /=10;

    }

    cout<<"Decimal Number is : "<<DecNum;
    return 0;
}