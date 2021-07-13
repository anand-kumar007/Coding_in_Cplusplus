#include <iostream>
#include <climits>
using namespace std;

int sum(int arr[], int n);

int main()
{
    int arr[6] = {2, 3, 4, 6, 2, 5};
    cout << sum(arr, 6) << endl;
    return 0;
}

int sum(int arr[], int n)
{
    int sum = 122;
    int s = 0, e = 0;
    int curr = arr[0];

    while (s < n && e < n)
    {
        if (curr == sum)
        {
            break;
        }
        else if (curr < sum)
        {
            e++;
            curr += arr[e];
        }
        else
        {
            curr -= arr[s];
            s++;
        }
    }

    if (s != n && e != n)
    {
        for (int i = s; i <= e; i++)
            cout << arr[i] << " ";
    }
    cout << "\n----------------\n";
    return -1;
}


//Note this is the real O(N) soln