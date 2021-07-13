#include <iostream>
using namespace std;
#define ull unsigned long long

ull factorial(int);

int main()
{
    int n,r;
    cout<<"enter n,r : ";
    cin>>n>>r;

    ull ans = factorial(n)/(factorial(r) * factorial(n-r)) ;

    cout<<"nCr = "<< ans ;

    return 0;

    
}


ull factorial(int num)
{
    ull fact = 1;
    for (int i = num; i >= 1; i--)
    {
        fact *= i;
    }

    return fact;
}