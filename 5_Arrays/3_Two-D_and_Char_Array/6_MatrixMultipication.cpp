/*
first's row and then second col
also since the output would be of nXq size

enter rows and cols for matrix 1 : 2 3
1 2 3
4 5 6
enter rows and cols for matrix 2 : 3 2
7 8
9 10
11 12

-----------Multiplication Matrix is-----------------
58 64
139 154

============================================
enter rows and cols for matrix 1 : 3 4
2 4 1 2
8 4 3 6
1 7 9 5
enter rows and cols for matrix 2 : 4 3
1 2 3
4 5 6
7 8 9
4 5 6

-----------Multiplication Matrix is-----------------
33 42 51
69 90 111
112 134 156
*/

#include <iostream>
using namespace std;

int main()
{
    int n = 3, m = 4, p = 4;
    int A[n][m];
    int B[m][p]; //this should be holding true to do the multiplication

    //1st ki row second ke cols(all) also refresh them

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> A[i][j];
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
            cin >> B[i][j];
    }

    //compute the output matrix
    int C[n][p];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            int temp = 0;
            for (int k = 0; k < m; k++)
            {
                temp += A[i][k] * B[k][j];
            }

            C[i][j] = temp;
        }
    }

    //print the output matrix
    cout << "\n---------------\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
            cout << C[i][j] << ' ';
        cout << endl;
    }
}
