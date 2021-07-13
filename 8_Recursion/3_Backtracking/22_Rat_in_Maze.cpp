/*
Rat In a Maze 

enter the path in binary form (1 for yes 0 for no path) : 
1 0 0 0
1 1 0 1
0 1 0 0
1 1 1 1
Path is :
1 0 0 0 
1 1 0 0 
0 1 0 0 
0 1 1 1 
=================
enter the path in binary form (1 for yes 0 for no path) : 
1 0 1 0 1
1 1 1 1 1
0 1 0 1 0
1 0 0 1 1
1 1 1 0 1
Path is : 
1 0 0 0 0 
1 1 1 1 0 
0 0 0 1 0 
0 0 0 1 1 
0 0 0 0 1 
=============
enter size of square maze : 5
enter the path in binary 
form (1 for yes 0 for no path) : 
1 0 1 0 1
1 1 1 0 1
0 1 0 1 0
1 0 0 1 1
1 1 1 0 1
No path exists !!

*/

#include <iostream>
using namespace std;
bool IsMoveSafe(int **maze, int n, int i, int j)
{
    if ((maze[i][j] == 1) && (i < n) && (j < n))
        return true;

    return false;
}

bool Rat_In_Maze(int **maze, int n, int i, int j, int **soln)
{
    //base condition
    if ((i == (n - 1)) && (j == (n - 1)))
    {
        soln[i][j] = 1;
        return true;
    }

    //algorithm
    if (IsMoveSafe(maze, n, i, j))
    {
        soln[i][j] = 1; //considering it to be a valid path

        // try to move horizontally and check path
        if (Rat_In_Maze(maze, n, i, j + 1, soln))
        {
            return true;
        }

        //try to move down and check the path
        if (Rat_In_Maze(maze, n, i + 1, j, soln))
        {
            return true;
        }

        //if none of above is possible, means our soln[i][j]
        //is not a part of our soln path
        //Backtrack

        soln[i][j] = 0;
        return false;
    }

    //if there is no such i,j

    return false;
}

int main()
{
    int n = 0;
    cout << "enter size of square maze : ";
    cin >> n;

    cout << "enter the path in binary form (1 for yes 0 for no path) : ";

    //allocate memory dynamically
    int **maze = new int *[n];
    for (int i = 0; i < n; i++)
    {
        maze[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> maze[i][j];
    }

    //memory allocation done
    int **soln = new int *[n];
    for (int i = 0; i < n; i++)
    {
        soln[i] = new int[n];
    }

    //initialize the soln matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            soln[i][j] = 0;
    }

    //check the path for the rat
    if (Rat_In_Maze(maze, n, 0, 0, soln))
    {
        cout << "Path is : \n";
        //print the soln path
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << soln[i][j] << ' ';
            cout << endl;
        }
    }

    //if not possible then print appropriate msg
    else
        cout << "No path exists !!";

    //free up the memory used
    for (int i = 0; i < n; i++)
    {
        delete[] maze[i];
        delete[] soln[i];
    }

    delete[] soln;
    delete[] maze;
    return 0;
}

/*
   //Delete the array created
      for(int i=0;i<m;i++)    //To delete the inner arrays
      delete [] a[i];   
      delete [] a;              //To delete the outer array
                              //which contained the pointers
                              //of all the inner arrays
*/