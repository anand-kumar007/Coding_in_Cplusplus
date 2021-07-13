/*
=============================
enter N : 5
    1   
   121  
  12321 
 1234321
123454321
=============================
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

        int j;
        for (j = 1; j <= (2 * i - 1) / 2; j++)
            cout<< j;

        for(; j>=1; j--)
        cout<<j;    

        cout<<endl;
    }
    return 0;
}