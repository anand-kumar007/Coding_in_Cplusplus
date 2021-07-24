/*
wave sort (not a sort acutally)
but an arrangement in the form of wave
O(n/2) or simply O(n) is its time complexity

===============
array is : 1 3 4 7 5 6 2 
wave sorted array is :   
3 1 7 4 6 2 5

=======
array is : 2 4 7 8 9 10 
wave sorted array is :  
4 2 8 7 10 9


*/

#include <iostream>
using namespace std;
void WaveSort(int arr[], int n);

int main()
{
    int arr[] = {2, 4, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;

    WaveSort(arr, n);

    cout << "wave sorted array is : \n";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    return 0;
}

void WaveSort(int arr[], int n)
{
    //each element should be less than
    //its aas paas wale elements

    for (int i = 1; i < n;)
    {
        if (arr[i] > arr[i - 1])
        {
            swap(arr[i], arr[i - 1]);
        }

        if ((arr[i] > arr[i + 1]) && (i <= n - 2))
        {
            swap(arr[i], arr[i + 1]);
        }

        i += 2;
    }

    return;
}