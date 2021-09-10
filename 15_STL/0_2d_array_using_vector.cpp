
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    //a 3X4 matrix is to be formed

    cout << "enter n and m : ";
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m, 0));

    cout << "enter " << n * m << "values : ";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << "formed matrix is : " << endl;

    for (vector<int> vct : arr)
    {
        for (int i : vct)
        {
            cout << i << "\t";
        }
        cout << endl;
    }
    return 0;
}

// vector<vector<int>> vect{
//     {1, 2, 3},
//     {4, 5, 6},
//     {7, 8, 9}};

// vector<vector<int>> vect{
//     {1, 2, 3},
//     {5, 6},
//     {9}};

// for (int i = 0; i < vect.size(); i++)
// {
//     for (int j = 0; j < vect[i].size(); j++)
//     {
//         cout << vect[i][j] << " ";
//     }
//     cout << endl;
// }

