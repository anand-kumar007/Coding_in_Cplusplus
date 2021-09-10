
/* smallest subsequence with sum > k */

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void SmallestSbSqSumGreaterThanK(vector<int> &arr, int k)
{
    priority_queue<int> maxpq; //cz minimum size needed so we are going
    //for greedy approach

    for (auto i : arr)
        maxpq.push(i);

    int sum = 0;
    int cnt = 0;
    while (!maxpq.empty())
    {
        sum += maxpq.top();
        maxpq.pop();
        cnt++;

        if (sum > k)
            break;
    }

    if (sum <= k)
        cout << "such subsquence dosen't exists" << endl;
    else
        cout << cnt << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cin >> k;
    SmallestSbSqSumGreaterThanK(arr, k);

    return 0;
}

/* 

5
1 1 3 2 8
13
4
=========
keep a max heap and insert all the elements to it
keep popping element form heap until sum > k
and maintain a count variable


*/
