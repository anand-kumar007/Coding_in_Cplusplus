/*
=================
enter n : 5
1
1  1
1  2  1
1  3  3  1
1  4  6  4  1
==================
Each term is a binomial cofficient 0C0,1C0 etc.
*/

#include <iostream>
using namespace std;
#define ull unsigned long long

ull fact(int);

int main()
{
    int n;
    cout << "enter n : ";
    cin >>n;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=i; j++)
        {
            ull ans = fact(i) / (fact(j) * fact(i - j));
            cout<<ans<<"  ";
        }
        cout <<endl;    
    }
    


    return 0;
}

ull fact(int num)
{
    if(num ==0 )
    return 1;

    ull fact = 1;
    for (int i = num; i >= 1; i--)
    {
        fact *= i;
    }

    return fact;
}