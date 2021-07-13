/*
Program to find the minimum (or maximum) element of an array.
*/
#include<iostream>
using namespace std;

int getMin(int arr[],int n)
{
    int res=0;
    for(int i=0;i<n; i++)
    res = min(res,arr[i]);

    return res;
}

int getMax(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
        res = max(res, arr[i]);

    return res;
}

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
    cout << "minimum element is : " << getMin(arr, n)<<endl;
    cout << "maximum element is : " << getMax(arr, n)<<endl;


    return 0;
}