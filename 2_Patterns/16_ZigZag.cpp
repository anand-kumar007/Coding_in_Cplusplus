/*
====================================
enter N : 9
  *   *  
 * * * * 
*   *   *
--------------
enter N : 27
  *   *   *   *   *   *   *
 * * * * * * * * * * * * * 
*   *   *   *   *   *   *  
====================================
*/

#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"enter N : ";
    cin>>n;

    for(int i=1; i<=3; i++)
    {
        for(int j=1; j<=n; j++)
        {
            // i==2 && j%4 ==0 or use this one
            if(((i+j)%4 ==0 )|| (i==2 && (i+j)%2 ==0))

            cout<<"*";

            else

            cout<<" ";
        }

        cout<<endl;
    }
    return 0;
}