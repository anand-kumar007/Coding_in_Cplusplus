/* Given a square matrix of size N x N find its transpose matrix

i/p --> 1 2 3    
        4 5 6 
        7 8 9       
o/p --> 1 4 7
        2 5 8
        3 6 9

A transpose matrix is obtained by flipping over the main diagonal
switching rows and cols indies.
like 2 was @(0,1) then 2 become @(1,0) so on

*/

#include <iostream>
using namespace std;

int main()
{
    int N;
    cout << "enter N for square matrix : ";
    cin >> N;
    int arr[N][N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
           { cin >> arr[i][j];
    }
    }

    //find the transpose matrix now

    for (int i = 0; i < N; i++)
    {
        //only upper half let say swap
        for (int j = i; j < N; j++)
        {
                // swap(arr[i][j], arr[j][i]);
                int temp = arr[i][j];
                arr[i][j] = arr[j][i];
                arr[j][i] = temp;
        }
    }

    cout << "\n----------Transpose matrix----------\n";

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << ' ';
        cout << endl;
    }
    return 0;
}