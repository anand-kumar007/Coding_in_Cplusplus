
#include <iostream>
#include <deque>
using namespace std;

void display(deque<int> q)
{
    int maxi = -1;

    for (auto item : q)
    {
        maxi = max(maxi, item);
    }

    cout << maxi << " ";
}
void printKMax(int arr[], int n, int k)
{

    if (k > n)
        return;
    deque<int> q;

    for (int i = 0; i < k; i++)
    {
        q.push_back(arr[i]);
    }

    display(q);
    for (int i = k; i < n; i++)
    {
        q.push_back(arr[i]);
        q.pop_front();
        display(q);
    }
}

int main()
{

    int t;
    cin >> t;
    while (t > 0)
    {
        int n, k;
        cin >> n >> k;
        int i;
        int arr[n];
        for (i = 0; i < n; i++)
            cin >> arr[i];
        printKMax(arr, n, k);
        t--;
    }
    return 0;
}
