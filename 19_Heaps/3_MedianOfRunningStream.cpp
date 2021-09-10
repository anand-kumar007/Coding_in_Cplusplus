/* 
find the median of running stream.

means numbers are coming and after each input we need to tell
the median of them.

1. brute force 
    after each input sort the array in asc and tell median
    this way
    n*(nlogn) --> n^2(logn) time

2. use the heaps

one is max heap and other is min heap
(i) insert in such a manner that asc order is maintained
(ii) size of two heaps differ by at most one

for median
if size are equal avg of top of both
else top of greater size is median

*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int, vector<int>> pqmax;
priority_queue<int, vector<int>, greater<int>> pqmin;

void insert(int x)
{
    if (pqmin.size() == pqmax.size())
    {
        if (pqmax.size() == 0)
        {
            pqmax.push(x); //lef we are choosing maxheap
            return;
        }
        //second case

        if (x <= pqmax.top())
            pqmax.push(x);
        else
            pqmin.push(x);
    }
    else
    {
        //again two cases
        if (pqmax.size() > pqmin.size())
        {
            //need to make size equal and maintain the order also
            if (x >= pqmax.top())
                pqmin.push(x);
            else
            {
                int temp = pqmax.top();
                pqmax.pop();

                pqmin.push(temp);
                pqmax.push(x);
            }
        }

        else
        {
            if (x <= pqmin.top())
                pqmax.push(x);

            else
            {
                int temp = pqmin.top();
                pqmin.pop();

                pqmax.push(temp);
                pqmin.push(x);
            }
        }
    }
}

double median()
{
    if (pqmin.size() == pqmax.size())
    {
        return (pqmin.top() + pqmax.top()) / 2.0;
    }
    else
    {
        if (pqmin.size() > pqmax.size())
            return pqmin.top();
        else
            return pqmax.top();
    }
}
int main()
{
    vector<int> arr = {10, 15, 21, 30, 18, 9};

    for (int i = 0; i < arr.size(); i++)
    {
        insert(arr[i]);
        cout << median() << " ";
    }
    return 0;
}

// easy
/* 
Time Complexity: O(n Log n). 
Time Complexity to insert element in min heap is log n. So to insert n element is O( n log n).
Auxiliary Space : O(n). 
The Space required to store the elements in Heap is O(n).
*/