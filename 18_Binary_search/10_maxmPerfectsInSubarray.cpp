
/* 

Given an array and integer k 
find the maxm perfect numbers in a subarray of size k

approach1:
generate subarray of size k and count number of perfects in each
subarray return the maxm of those.
==> wheher done using sliding window also whole list has to be traversed
complexity-> O(n*k) where k<=n so may go upto O(N^2)

approach2:

let's replace perfects in array with 1 and others with 0
then our problem is to find maxm sum subarray of size k

time analysis :
O(n) for travesing array and checking each element is perfectO(sqrt(n))
overall ==> O(n*sqrt(n))

and sliding window takes O(n) which is separate
so 

O(n*sqrt(n)) is final time complexity

*/

#include <iostream>
#include <cmath>
using namespace std;

bool isPerfect(int num)
{
    int sum = 1; //even 1 is also a divisor

    for (int i = 2; i < sqrt(num); i++)
    {
        if (num % i == 0)
        {
            if (i == num / i)
                sum += i;
            else
                sum += i + num / i;
        }
    }

    if (sum == num && num != 1)
        return true;
    return false;
}

int maxmPerfects(int arr[], int n, int k)
{
    //traverse whole array and tweak it
    for (int i = 0; i < n; i++)
    {
        if (isPerfect(arr[i]))
            arr[i] = 1;
        else
            arr[i] = 0;
    }

    //above methods took O(n*sqrt(n)) time
    //apply the sliding window maxm now
    int sum = 0; //to store maxm sum of subarray
    int ans = 0;

    for (int i = 0; i < k; i++)
        sum += arr[i];

    ans = sum;

    for (int i = k; i < n; i++)
    {
        sum = sum - arr[i - k] + arr[i];
        if (sum > ans)
            ans = sum;
    }

    return ans;
}

int main()
{
    int arr[] = {28, 2, 3, 6, 496, 99, 8128, 24}; // K = 4
    // int arr[] = {1,2,3,4,6}; // k=2
    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 4;

    int ans = maxmPerfects(arr, n, k);

    cout << "maxm perfect in window are : " << ans << endl;
    return 0;
}
