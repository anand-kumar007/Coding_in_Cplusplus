/*
maxm 1's in array
Given an array of 0s and 1s , you may change
upto k elements from 0 to 1.

Return the length of the longest(contiguous)
subarray that contains only 1s

eg :
arr = [1,1,1,0,0,0,1,1,1,1,0]  k=2
output = 6
since [-,-,-,0,0,1,1,1,1,1,1]

here problem reduces to finding the longest
subarray that contains atmost k zeros 

=> for each A[i..j]
=> if count_zeros <k then A[i..j+1] window size expands
==> if count_zeros > k then A[i+1..j] window size shrinks

*/

#include <iostream>
#include <vector>
using namespace std;

int Size_of_1s(vector<int> arr, int k);

int main()
{
    // vector<int> arr = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    vector<int> arr = {1, 1, 0, 0, 1};
    int k = 2;

    cout << Size_of_1s(arr, k) << endl;
    return 0;
}

int Size_of_1s(vector<int> arr, int k)
{
    int count_zeros = 0, i = 0, ans = 0;
    int n = arr.size();

    for (int j = 0; j < n; j++)
    {
        if (arr[j] == 0)
        {
            count_zeros++;
        }
        while (count_zeros > k)
        {
            if (arr[i] == 0)
            {
                count_zeros--;
            }
            i++;
        }

        // count_zeros <=k
        ans = max(ans, j - i + 1);
    }

    return ans;
}