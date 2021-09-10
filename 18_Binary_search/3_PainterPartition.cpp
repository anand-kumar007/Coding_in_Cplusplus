
/* 
minimum time to paint the boards

each painter paints consecutive boards only and 1 unit time to paint one lengt of baord
by any painter

the problem is same as Allocate MinPages one
bcz

n-> boards of lenghts [10,20,30,40]
m-> painters 

n = 4
m = 2

possible combinations
10 20 30 , 40 --> max time by single painter = 60
10 20 , 30 40 --> max time by single painter = 70
10, 20 30 40  --> max time by single painter = 90

so minimum taken to paint would be Max time taken by
single painter bcz other will finish their jobs earlier

so the answer is : 60 units of time

*/

#include <iostream>
#include <climits>
using namespace std;

int findFeasible(int arr[], int n, int limit)
{
    int sum = 0, painter = 1;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > limit)
        {
            sum = arr[i];
            painter++;
        }
    }

    return painter;
}

int MinTimeToPaint(int arr[], int n, int m)
{

    int totalLength = 0, k = 0;
    //k will store the maxm board length
    //that would the starting range(Max value)
    //for our range

    for (int i = 0; i < n; i++)
    {
        totalLength += arr[i];
        k = max(k, arr[i]);
    }

    int low = k;            //start(min Time taken intially)
    int high = totalLength; //upper limit

    while (low < high)
    {
        int mid = (low + high) / 2;

        //how many painter we need for this mid value
        int painter = findFeasible(arr, n, mid);

        if (painter <= m)
        {
            //search for the left half
            //for lesser value
            high = mid;
        }
        else
            low = mid + 1; //search in right half

        //ans would be in low
    }

    return low;
}

int main()
{
    int boards[] = {10, 20, 30, 40}; //ans = 60 if m = 2
    // int boards[] = {10, 20, 30, 40};

    int n = sizeof(boards) / sizeof(boards[0]);
    int total_painters = 2;

    int ans = MinTimeToPaint(boards, n, total_painters);

    cout << ans << endl;

    return 0;
}