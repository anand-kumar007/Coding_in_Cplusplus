/*
Given an array of integers, find the first 
repeating element in it. We need to find the 
element that occurs more than once and whose 
index of first occurrence is smallest. 

Examples: 

Input:  arr[] = {10, 5, 3, 4, 3, 5, 6}
Output: 5 [5 is the first element that repeats] 
print its index(smaller one)

Input:  arr[] = {6, 10, 5, 4, 9, 120, 4, 6, 10}
Output: 6 [6 is the first element that repeats]
print its index(smaller one)

*/
#include <iostream>
#include <climits>
using namespace std;
int findIndex(int arr[],int);

int main()
{
    int n;
    cout<<"enter N : ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    cin>>arr[i];

    int ans = findIndex(arr,n);

    if(ans != -1)
    cout<<"minimum index is : "<<ans;
    else 
    cout<<"no repeating element ";

    return 0;
}

int findIndex(int arr[], int n)
{
    const int N = 1e6 + 2; //10^6 + 2
    int Idx[N];
    int minIdx = INT_MAX;
    for (int i = 0; i < N; i++)
        Idx[i] = -1;

   
    for (int i = 0; i < n; i++)
    {
        if (Idx[arr[i]] != -1)
        {
            //this could be our potential answer
            //choose minimum if it is.
            //and no need to change Idx[arr[i]] again
            minIdx = min(minIdx, Idx[arr[i]]);
        }

        else //simply do this
            Idx[arr[i]] = i;
    }

    if(minIdx == INT_MAX)
    return -1;
    else 
    return minIdx;


}