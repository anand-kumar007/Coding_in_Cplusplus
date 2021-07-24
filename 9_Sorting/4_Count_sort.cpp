/*
Count sort algorithm
Time Complexity: O(n+k) where n is the number of elements in input array and k is the range of input. 
Auxiliary Space: O(n+k)
 

The problem with the previous counting sort was that we could 
not sort the elements if we have negative numbers in it. 
Because there are no negative array indices. So what we do is, 
we find the minimum element and we will store count of that minimum element at zero index.

*/

#include <iostream>
void countSort(int arr[], int n);

using namespace std;
int main()
{
    int arr[] = {1, 3, 2, 3, 4, 1, 6, 4, 3};
    int n = 9;
    countSort(arr, n);

    cout << "sorted array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    return 0;
}

void countSort(int arr[], int n)
{
    int output[n];
    //make an array of maxm element size from i/p array
    int k = arr[0];
    for (int i = 0; i < n; i++)
    {
        k = max(k, arr[i]);
    }

    int count[k + 1] = {0};

    //fill the frequencies
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    //modify the count array to hold the positions
    //modified count array

    // Change count[i] so that count[i] now contains actual
    // position of this character in output array
    for (int i = 1; i <= k; i++)
    {
        count[i] += count[i - 1];
    }

    //traverse the input array from last and come to
    //that index in count array decrement it
    //and go to that index in O/P array fill in the value

    for (int i = n - 1; i >= 0; i--)
    {
        output[--count[arr[i]]] = arr[i];
    }

    //copy output array to input array
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }

    return;
}