

#include <iostream>
#include <vector>
#include <set>
using namespace std;
bool isSodukoValid(vector<vector<char>> &board)
{
    //maintain sets for each row,box and column
    //9 rows,9 cols, 9 boxes

    vector<set<int>> rows(9), cols(9), box(9);

    //loop through each of the cell and check for their validity

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != '.')
            {
                int curr = board[i][j] - '0';
                //cz 3X3 size box so divide by three
                int num = (i / 3) * 3 + j / 3; //represent box num for (i,j) cell

                if (rows[i].count(curr) ||
                    cols[j].count(curr) ||
                    box[num].count(curr))
                    return false;

                //or simply insert them to the respective sets
                rows[i].insert(curr);
                cols[j].insert(curr);
                box[num].insert(curr);
            }
        }
    }

    return true;
}

int main(void)
{
    vector<vector<char>> board =
        {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
         {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
         {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
         {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
         {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
         {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
         {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
         {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
         {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    cout << isSodukoValid(board) << endl;

    return 0;
}