/*
=====================================
enter rows : 5
1
2       3
4       5       6
7       8       9       10
11      12      13      14      15

======================================
*/

#include <iostream>
using namespace std;

int main()
{
    int rows;
    cout << "enter rows : ";
    cin >> rows;

    int count=1;

    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= i; j++)
           { cout << count<<'\t';
            count++;
           }

        cout << endl;
    }

    return 0;
}