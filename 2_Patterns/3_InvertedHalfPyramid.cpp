/* 
==================
enter N : 5 
enter symbol : ^

^^^^^
^^^^
^^^
^^
^

======================

*/

#include<iostream>
using namespace std;

int main()
{
    int n;
    char symbol;
    cout<<"enter N : ";
    cin>>n;

    cout<<"enter symbol : ";
    cin>>symbol;
    for(int i=n; i>=1; i--)
    {
        for(int j=1; j<=i; j++)
        cout<<symbol;


        cout<<endl;
    }
    return 0;
}