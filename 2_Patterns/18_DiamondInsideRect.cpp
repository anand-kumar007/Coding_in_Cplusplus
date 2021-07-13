/*
======================================
enter N : 5
*********
**** ****
***   ***
**     **
*       *
*       *
**     **
***   ***
**** ****
*********
======================================
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "enter N : ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            for (int j = 1; j <= 2 * n - 1; j++)
                cout << "*";

            cout << endl;
        }

        else
        {
                //2-5
            for (int j = 1; j <= (n - i+1); j++)
                cout << "*";

            //spaces
            for (int k = 1; k <= (2 * i - 3); k++)
                cout << " ";

            for (int j = 1; j <= (n - i +1); j++)
                cout << "*";

            cout << endl;
        }
    }

    // lower half
    for (int i = n; i >= 1; i--)
    {
        if (i == 1)
        {
            for (int j = 1; j <= 2 * n - 1; j++)
                cout << "*";

            cout << endl;
        }

        else
        {

            for (int j = 1; j <= (n - i + 1); j++)
                cout << "*";

            //spaces
            for (int k = 1; k <= (2 * i - 3); k++)
                cout << " ";

            for (int j = 1; j <= (n - i + 1); j++)
                cout << "*";

            cout << endl;
        }
    }

return 0;
}


//Upper half logic
// idea is simple if i==1 print all starts
//else starts---spaces--stars