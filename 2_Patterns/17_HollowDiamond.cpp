/*
======================================
enter N : 5
    *
   * *
  *   *
 *     *
*       *
*       *
 *     *
  *   *
   * *
    *
======================================
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

        for(int j=1; j<= (2*i - 1); j++)
        {
            if(j==1 || j == (2*i -1))
            cout<<"*";

            else 
            cout<<" ";
        }

        cout<<endl;
    }

    // lower half

    for (int i = n; i >=1; i--)
    {
        //spaces
        for (int j = 1; j <= n - i; j++)
            cout << " ";

        for (int j = 1; j <= (2 * i - 1); j++)
        {
            if (j == 1 || j == (2 * i - 1))
                cout << "*";

            else
                cout << " ";
        }

        cout << endl;
    }

    return 0;
}