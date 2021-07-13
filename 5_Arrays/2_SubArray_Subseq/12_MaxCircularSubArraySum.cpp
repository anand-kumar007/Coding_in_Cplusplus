//using O(2N) space complexity and Kadanes algorithm
// gives us maxm ciruclar subarray sum
// here wrapping may be needed or may not be
/*
Enter N : 6
-1 4 -6 7 5 -4
maximum circular subarray sum is : 12

Enter N : 7
4 -4 6 -6 10 -11 12
maximum circular subarray sum is : 22

contributing --> which adds to give maxsum

if contributing elements are non-wraping then 
non-contributing elements will be wrapping and vice vers.
*/

#include<iostream>
#include<climits>
using namespace std;
void maxCirculaSubArraySum(int arr[],int n);
int kadanes(int arr[] ,int );

int main()
{
    int n;
    cout<<"Enter N : ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    cin>>arr[i];

    int wrapsum;
    int nonwrapsum;
    int totalArraySum=0;
    //non wrapsum can be accessed using kadanes
    nonwrapsum = kadanes(arr,n);

    //calculate the wrapsum
    // for that first reverse the sign of the elements
    //and lets calculate the sum of total array here only
    for(int i=0; i<n; i++)
    {
        totalArraySum += arr[i];
        arr[i] = - arr[i];
    }

    // wrapsum = totalArraySum - (-1* kadanes(arr,n));
    wrapsum = totalArraySum + kadanes(arr, n);

    cout<<"maximum circular subarray sum is : "<<max(wrapsum,nonwrapsum);
    return 0;
}




int kadanes(int aux[],int N)
{
    int currSum = 0;
    int maxSum = INT_MIN;

    for (int i = 0; i < N; i++)
    {
        currSum += aux[i];

        if (currSum < 0)
            currSum = 0;
        if(maxSum < currSum)
          maxSum = currSum;
    }

    return maxSum;
}

 