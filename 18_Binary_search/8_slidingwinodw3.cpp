

/*
given an array and value k

find the subarray of size k whose values
sum comes out to divisible by three

*/

#include <iostream>
#include <vector>
using namespace std;

void computeSum(vector<int> arr, int k)
{
    pair<int, int> ans;
    int sum = 0;

    for (int i = 0; i < k; i++)
        sum += arr[i];

    bool found = false;
    if (sum % 3 == 0)
    {
        ans = make_pair(0, k - 1);
        found = true;
    }

    for (int i = k; i < arr.size(); i++)
    {
        if (found)
            break;
        sum = sum + arr[i] - arr[i - k];
        if (sum % 3 == 0)
        {
            ans = make_pair(i - k + 1, i);
            found = true;
        }
    }

    if (found)
    {
        for (int i = ans.first; i <= ans.second; i++)
            cout << arr[i] << " ";
    }
    else
        cout << "ans doesn't exists !" << endl;
}

int main()
{
    vector<int> arr = {84, 23, 45, 12, 56, 82};

    int k = 3;
    computeSum(arr, k);
    return 0;
}

// 12 56 82