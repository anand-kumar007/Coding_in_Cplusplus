/*
========================
enter N : 5
    1     
   2 2    
  3 3 3   
 4 4 4 4  
5 5 5 5 5 
========================
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

        for(int j=1; j<=i; j++)
        cout << i << " ";
        // cout << j << " ";

        cout<<endl;
    }
    return 0;
}