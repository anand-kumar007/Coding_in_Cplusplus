/*
=========================
enter N : 5
enter symbol : ^
    ^
   ^^
  ^^^
 ^^^^
^^^^^

==========================

*/

#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"enter N : ";
    cin>>n;

    char symbol;
    cout<<"enter symbol : ";
    cin>>symbol;

    // int space = n -1;

    // for(int i=1; i<=n; i++)
    // {
    //     for(int j=1; j<=space; j++)
    //     cout<<" ";

    //     for(int j=1; j<=i; j++)
    //     cout<<symbol;

    //     cout<<endl;

    //     space = space -1;
    // }


    // second concise way of doing this

    int space = n-1;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(j <= space)
            cout<<" ";
            else
            cout<<symbol;
        }
        space -= 1;
        cout<<endl;
    }

    return 0;
}