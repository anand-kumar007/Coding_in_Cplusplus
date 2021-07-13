/*
================================
enter N : 5
    *****
   *   *
  *   *
 *   *
*****
================================
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
        //spaces
        for(int j=1; j<= n-i; j++)
        cout<<" ";

        for(int j=1; j<=n; j++)
        {
            if(i==1 || i==n)
            cout<<"*";
            else 
            {
            if(j==1 || j==n)
            cout<<"*";
            else
            cout<<" ";
            }
        }

        cout<<endl;
    }
    return 0;
}