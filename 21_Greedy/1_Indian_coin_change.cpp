
/* 
You are given an array of denomination and value x you are required to find the
minimum number of coins required to make value x. 

NOTE : we have infinite supply of each coin
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto &i : arr)
        cin >> i;

    int Amount;
    cin >> Amount;

    sort(arr.begin(), arr.end(), greater<int>());
    int count = 0;
    for (int i = 0; i < n;)
    {

        if (arr[i] <= Amount)
        {
            Amount -= arr[i];
            count++;
            if (Amount == 0)
                break;
            continue;
        }
        i++;
    }
    cout << count << endl;
    return 0;
}

/* 
the main idea of greedy approach is

Take the best suitable path from the current position.


1. Generally sorting is done while applying greedy techniques
2. Sometimes we don't realize we are  using greedy but we do. 
   it comes inherently!!


*/
