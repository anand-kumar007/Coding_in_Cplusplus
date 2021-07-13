/*
The Famous N-Queen Problem
=============
enter N : 4
solution is  :
0 1 0 0 
0 0 0 1 
1 0 0 0 
0 0 1 0 
============
enter N : 6
solution is  :
0 1 0 0 0 0   
0 0 0 1 0 0   
0 0 0 0 0 1   
1 0 0 0 0 0   
0 0 1 0 0 0   
0 0 0 0 1 0  
===============
*/
#include <iostream>
using namespace std;
bool isSafe(int **board, int x, int y, int n);
bool NQueen(int **board, int x, int n);

int main()
{
    int n;
    cout << "enter N : ";
    cin >> n;
    int **board = new int *[n];

    for (int i = 0; i < n; i++)
    {
        board[i] = new int[n];
        for (int j = 0; j < n; j++)
            board[i][j] = 0;
    }

    //apply algorithm
    if (NQueen(board, 0, n))
    {
        cout << "solution is  :\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << board[i][j] << ' ';
            cout << endl;
        }
    }

    else
        cout << "solution doesn't exists !!";

    //free up the memory

    for (int i = 0; i < n; i++)
    {
        delete[] board[i];
    }
    delete[] board;
    return 0;
}

bool NQueen(int **board, int x, int n)
{
    //base case(when all queens are placed)
    if (x >= n)
    {
        return true;
    }

    //check for cols from 0 to n
    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, x, col, n))
        {
            board[x][col] = 1;

            if (NQueen(board, x + 1, n))
                return true;

            //else backtrack
            board[x][col] = 0;
        }
    }

    //if no such position possible
    return false;
}

bool isSafe(int **board, int x, int y, int n)
{
    //upward in same column
    for (int row = 0; row < x; row++)
    {
        if (board[row][y] == 1)
            return false;
    }

    //left and right diagonal respectively
    int row = x;
    int col = y;

    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 1)
            return false;

        row--;
        col--;
    }

    row = x;
    col = y;

    while (row >= 0 && col < n)
    {
        if (board[row][col] == 1)
            return false;

        row--;
        col++;
    }

    //else path is safe
    return true;
}