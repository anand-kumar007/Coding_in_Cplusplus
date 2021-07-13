/*
given a number tell how many ones its binary
form contains

same concept like
(n & n-1) has same bits as n except the rightmost set bit
and each time n and n&(n-1) differ in one bit that is 1

n=3, 0011
n-1=2 0010

n = n&n-1 ie 0010  (2)

again
n-1 = 1, 0001

so 
n = n&n-1 ie 0000 
so total ones in n=3 is two

*/

#include <iostream>
using namespace std;
#define ULLI unsigned long long int

int CountOnes(int n);
ULLI DecimalToBinary(int n);

int main()
{
    int n;
    cout << "Enter a number : ";
    cin >>n;

    cout<<"Total ones are : "<<CountOnes(n)<<endl;

    cout<<"binary form of number is : "<<DecimalToBinary(n); 
    return 0;
}

int CountOnes(int n)
{
    int count=0;
    while(n) // n!=0
    {
        n= n & n-1;
        count++;
    }

    return count;
}

ULLI DecimalToBinary(int n)
{
    int x=1;
    ULLI ans=0;
    
    while(x<=n)
    {
        x *=2;
    }
    x= x/2;

    int quotient=0;

    while(x>0)
    {
        quotient = n/x;
        n = n - quotient*x;
        ans = ans*10 + quotient;
        x = x/2;

    }
  return ans;

}

// complexity : number of 1's in n(which is constantly < 32).