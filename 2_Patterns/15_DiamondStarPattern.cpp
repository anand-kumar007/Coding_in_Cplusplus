/*
==============================
enter N : 4
   *   
  ***  
 ***** 
*******
*******
 ***** 
  *** 
   *  
===============================
*/

#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"enter N : ";
    cin>>n;
    //upper pyramid

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n-i; j++)
        cout<<" ";

        for(int j=1; j<= (2*i -1); j++)
        cout<<"*";

        cout<<endl;
    }

    //lower pyramid
    //just iterate from n to 1 for rows
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n - i; j++)
            cout << " ";

        for (int j = 1; j <= (2 * i - 1); j++)
            cout << "*";

        cout << endl;
    }
    return 0;
}