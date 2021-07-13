/*
Kadanes algorithm says if there are more negative
numbers in contigous subarray then sum will 
become negative so  drop that and
reset the sum to 0;

-1 4 -6 7 -4
==> sum is 7
-1 4 7 2
==>sum is 13
*/
//print all the subarray of an array

#include <iostream>
#include<climits>
using namespace std;
void MaxSubArraysum(int arr[], int n);
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

    MaxSubArraysum(arr, n);
    return 0;
}
void MaxSubArraysum(int arr[], int n)
{
  int maxSum = INT_MIN;
  int currSum = 0;

  for(int i=0; i<n; i++)
  {
      if(currSum < 0)
      {
          currSum = 0;
      }

      currSum += arr[i];
      maxSum = max(maxSum,currSum);
  }

  cout<<maxSum;
}

// it's the most optimized algo with O(N) time complexity