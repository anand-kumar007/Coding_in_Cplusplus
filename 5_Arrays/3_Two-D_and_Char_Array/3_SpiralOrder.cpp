/*
traverse the array in the spiral order
like if 
4X4 array is there
1  2  3  4
5  6  7  8
9  10 11 12
13 14 15 16

--> its spiral order traversal would be
1 2 3 4 8 12 16 15 14 13 9 5,
6 7 11 15 14 10
*/
#include<iostream>
using namespace std;
void SpiralOrder(int arr[][4], int n, int m);

int main()
{
    int n,m;
    cout<<"enter rows and cols : ";
    cin>>n>>m;
    int arr[n][m];

    cout<<"enter the elements of matrix : "<<endl;
   for(int i=0; i<n; i++)
   {
     for(int j=0; j<m;j++)
        cin>>arr[i][j];
   }

    //======================================================

   //we need four variable to traverse
   int row_start = 0, row_end = n - 1, col_start = 0, col_end = m - 1;

   cout<<"\n----------\n"; 
   while (row_start <= row_end && col_start <= col_end)
   {
       //---->Horizonatl LtoR travaersal
       for (int i = col_start; i <= col_end; i++)
           cout << arr[row_start][i]<<" ";
       row_start++;

       // vertically down TtoB traversal @col_end
       for (int i = row_start; i <= row_end; i++)
           cout << arr[i][col_end]<<" ";
       col_end--;

       //horizontal RtoL traversal
       for (int i = col_end; i >= col_start; i--)
           cout << arr[row_end][i]<<" ";
       row_end--;

       //vertiacally up BtoT traversal
       for (int i = row_end; i >= row_start; i--)
           cout << arr[i][col_start]<<" ";
       col_start++;

       //repeat the process
       cout << "\n---------------" << endl;
   }

    return 0;
}

void SpiralOrder(int arr[][4], int n, int m)
{
    //for traversing in spiral order we need four variables
    int row_start = 0, row_end = n - 1;
    int col_start = 0, col_end = m - 1;
    int i, j;
    while (row_start <= row_end && col_start <= col_end)
    {
        i = row_start;
        for (j = col_start; j <= col_end; j++)
            cout << arr[i][j] << " ";
        row_start++;

        j = col_end;
        for (i = row_start; i <= row_end; i++)
            cout << arr[i][j] << " ";
        col_end--;

        i = row_end;
        for (j = col_end; j >= col_start; j--)
            cout << arr[i][j] << " ";
        row_end--;

        j = col_start;
        for (i = row_end; i >= row_start; i--)
            cout << arr[i][j] << " ";
        col_start++;

        cout << endl;
    }
    return;
}