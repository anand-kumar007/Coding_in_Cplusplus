// using for loops it is very easy
/*
stars---spaces---stars
repeat and chill
=================== 
*          *
**        **
***      ***
****    ****
*****  *****
************
************
*****  *****
****    ****
***      ***
**        **
*          *
===================
*/

#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"enter N : ";
    cin>>n;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=i; j++)
        {
            cout<<"*";
        }

        for(int j=1; j<= (2*n - 2*i); j++)
        {
            cout<<" ";
        }

        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout<<endl;  
    }

    // first part is done for second part just use i=n to 1
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }

        for (int j = 1; j <= (2 * n - 2 * i); j++)
        {
            cout << " ";
        }

        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }

        cout << endl;

        
    }
    return 0;
}