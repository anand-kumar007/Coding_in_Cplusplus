//arithmetic subarray is one whose consecutive elements differ by same 
//[3,3,3],[9,10],[9,7,5,3] --> these are 9 elements

//find length of maximum Arithmatic subarray
/*
Enter N : 7
enter 7 elements :
10 7 4 6 8 10 11
Length of largest Arithmetic array is : 4
*/


#include <iostream>
using namespace std;
int LongestAParray(int arr[], int n);

int main()
{
    int n;
    cout << "Enter N : ";
    cin >> n;
    int arr[n];
    cout << "enter " << n << " elements :\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Length of largest Arithmetic array is : " << LongestAParray(arr, n);
    return 0;
}

int LongestAParray(int arr[], int n)
{
    int pd = arr[1]-arr[0];
    int currLength = 2;
    int ans = 2;

    int j=2;

    while(j<n)
    {
        if(pd == arr[j]-arr[j-1])
        {
            currLength++;
           
        }
        else 
        {
            //update the difference and reset the currLength
            pd = arr[j]-arr[j-1];
            currLength=2;
        }

        ans = max(ans, currLength);
        j++;
    }

    return ans;
}

    

/* just the O(N)  see.
*/