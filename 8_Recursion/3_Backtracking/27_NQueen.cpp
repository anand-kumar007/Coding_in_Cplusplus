#include <iostream>
#include <vector>
using namespace std;

bool NQeen(vector<vector<int>> &board, int x, int N);
bool isSafe(vector<vector<int>> &board, int x, int y, int N);

int main(void)
{
    int N;
    cout << "Enter size of Square Board(N) : ";
    cin >> N;

    vector<vector<int>> board(N, vector<int>(N, 0));

    bool check = NQeen(board, 0, N);

    if (!check)
        cout << "No solution exists!" << endl;
    else
    {
        for (auto vect : board)
        {
            for (auto i : vect)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

bool NQeen(vector<vector<int>> &board, int x, int N)
{
    if (x >= N)
        return true;

    for (int col = 0; col < N; col++)
    {
        if (isSafe(board, x, col, N))
        {
            board[x][col] = 1;

            if (NQeen(board, x + 1, N))
                return true;
            //else backtrack
            board[x][col] = 0;
        }
    }

    return false;
}

//rows safe checking is not needed since we start looking
//from first col and as soon as we found position we move to next row
bool isSafe(vector<vector<int>> &board, int x, int y, int N)
{
    //1. check in upward in same column
    for (int col = x; col >= 0; col--)
    {
        if (board[col][y] == 1)
            return false;
    }

    //2. check for the diagonal in left and right(only upward)

    //left upper diagonal
    int row = x;
    int col = y;

    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 1)
            return false;
        row--;
        col--;
    }

    //upper right diagonal
    row = x;
    col = y;

    while (row >= 0 && col < N)
    {
        if (board[row][col] == 1)
            return false;
        row--;
        col++;
    }

    //if nothing is violated then path is safe
    return true;
}