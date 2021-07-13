/*
given an array check is it 
sorted in ascending order or not
*/

#include <iostream>
using namespace std;
bool checkSorted(int arr[],int n);
bool checkRecursive(int arr[],int n);

int main()
{
    int n;
    cout << "enter N : ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << checkRecursive(arr, n) << endl;
    // cout << checkSorted(arr, n) << endl;
    return 0;
}

bool checkRecursive(int arr[], int n)
{
   if(n==1)
   return true;

   //checking if rest of the array is sorted or not
   bool restArray = checkRecursive(arr+1,n-1); 
   if(arr[0]<arr[1] && restArray)
   {
       return true;
   }
   else 
   return false;

}

bool checkSorted(int arr[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        if(arr[i+1]<arr[i])
        {
            return false;
        }
    }

    return true;
}