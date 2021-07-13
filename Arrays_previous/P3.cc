/*
Write a program to reverse an array or string.

*/
// ==> O(N) complexity

/*
Program to find the minimum (or maximum) element of an array.
*/
#include <iostream>
using namespace std;

void reverseArray(int arr[], int n);
void reverseArray2(int arr[], int n);

int main()
{
    int n;
    cout << "enter size : ";
    cin >> n;
    int arr[n];
    cout << "enter " << n << " array elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> *(arr + i);
    }

    cout << "array is :";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl
         << "============" << endl;
   
    reverseArray2(arr,n);
    cout<<"Reversed array is : "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<< *(arr + i)<<" ";
    }

    return 0;
}

void reverseArray(int arr[], int n)
{
    int temp =-1;
    int start = 0;
    int end = n-1;

    while(start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        end--;
        start++;
    }
}

void reverseArray2(int arr[], int n)
{
    int temp=-1;
    for(int i=0; i<n/2; i++)
    {
        temp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = temp;
    }

}
