#include <iostream>
#include <vector>

using namespace std;

vector<vector<string>> res;

void NQueen(vector<string> &board, int x);
bool isSafe(vector<string> &board, int x, int y);

vector<vector<string>> solveNQueens(int n)
{
    if (n <= 0)
        return {{}};

    vector<string> board(n, string(n, '.'));

    NQueen(board, 0);

    return res;
}

int main()
{
    int n;
    cout << "enter N : ";
    cin >> n;

    res = solveNQueens(n);

    cout << "\n------------\n"
         << endl;
    if (res.size() != 0)
    {
        for (auto vect : res)
        {
            for (auto s : vect)
                cout << s << endl;
            cout << "\n---\n";
        }
    }
    cout << "Total Possible ways :" << res.size() << endl;
    return 0;
}

void NQueen(vector<string> &board, int x)
{
    if (x == board.size())
    {
        res.push_back(board);
        return;
    }

    for (int col = 0; col < board.size(); col++)
    {
        if (isSafe(board, x, col))
        {
            board[x][col] = 'Q';
            NQueen(board, x + 1);

            //backtrack(not like trivial case where if we were founding)
            //the result we were returing and if not we were backracking
            //here we are seeing all combinations like prinring all the
            //permutations
            board[x][col] = '.';
        }
    }

    return;
}

bool isSafe(vector<string> &board, int x, int y)
{
    //1. upside in same column
    for (int col = x; col >= 0; col--)
    {
        if (board[col][y] == 'Q')
            return false;
    }

    //2. left upper diagonal
    int row = x;
    int col = y;

    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }

    //3. upper right column
    row = x;
    col = y;

    while (row >= 0 && col <= board.size())
    {
        if (board[row][col] == 'Q')
            return false;
        row--;
        col++;
    }

    return true;
}