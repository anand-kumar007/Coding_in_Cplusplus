/*
========================
enter N : 5

    * * * * * 
   * * * * *  
  * * * * *   
 * * * * *
* * * * *
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
        for(int j=1; j<=n-i; j++)
        cout<<" ";

        //element
        for(int j=1; j<=n; j++)
        cout<<"* ";

        cout<<endl;
    }
    return 0;
}