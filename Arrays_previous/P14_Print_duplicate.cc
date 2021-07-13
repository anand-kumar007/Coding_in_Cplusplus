
//print the duplicate elements in the array

#include <bits/stdc++.h>
using namespace std;
void printDuplicates(int arr[], int);
int main()
{
    int n;
    cout << "size : ";
    cin >> n;
    int arr[n];
    cout << "enter " << n << " numbers : ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

     printDuplicates(arr, n);

    return 0;
}

void printDuplicates(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i]== arr[j])
            {
                cout << arr[i]<<" ";
                
            }
        }
    }

    
}
