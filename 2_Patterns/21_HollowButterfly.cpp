// using for loops it is very easy
/*
=================== 
enter N : 5
*        *
**      **
* *    * *
*  *  *  *
*   **   *
*   **   *
*  *  *  *
* *    * *
**      **
*        *
===================
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"enter N : ";
    cin>>n;

    //upper half
    for(int i=1; i<=n; i++)
    {
        //stars
        for(int j=1; j<=i; j++)
        {
            if (j == 1 || j == i)
                cout << "*";
            else
                cout << " ";
        }

        //spaces
        for(int j=1; j<= (2*n - 2*i); j++)
        cout<<" ";

        //stars
        for (int j = 1; j <= i; j++)
        {
            if (j == 1 || j == i)
                cout << "*";
            else
                cout << " ";
        }

        cout<<endl;
    }
   
    //lower half

    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
            {   
                if(j==1 || j==i)
                cout << "*";
                else
                cout<<" ";
            }
        for (int j = 1; j <= (2 * n - 2 * i); j++)
            cout << " ";

        for (int j = 1; j <= i; j++)
        {
            if (j == 1 || j == i)
                cout << "*";
            else
                cout << " ";
        }

        cout << endl;
    }

    return 0;
}