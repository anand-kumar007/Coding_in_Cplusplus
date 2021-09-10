
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void mergeKsorted(vector<vector<int>> &arr, int k)
{
    vector<int> idx(k, 0); //for storing current idx of array in heap(its indices show array number)
    vector<int> ans;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minpq;

    for (int i = 0; i < k; i++)
    {
        //input first element of each array into heap(along with array number) and idx array accordingly
        minpq.push({arr[i][0], i});
        idx.push_back(0);
    }

    while (!minpq.empty())
    {
        pair<int, int> temp = minpq.top();
        minpq.pop();

        ans.push_back(temp.first);

        //insert next element of same array(if exists) in heap
        if (idx[temp.second] + 1 < arr[temp.second].size())
        {
            //temp.second holds the array number
            minpq.push({arr[temp.second][idx[temp.second] + 1], temp.second});

            //update the index array
            idx[temp.second] += 1;
        }
    }

    cout << "\n--------------------" << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return;
}

int main()
{
    int k = 3;

    vector<vector<int>> arr(k);
    cout << "enter size and then elements for " << k << " sorted arrys :\n";

    for (int i = 0; i < k; i++)
    {
        int size;
        cin >> size;

        arr[i] = vector<int>(size);

        for (int j = 0; j < size; j++)
            cin >> arr[i][j];
    }
    cout << "\n-------------" << endl;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    mergeKsorted(arr, k);
    return 0;
}

/* 
best solution 
1. make a minheap
2. inset first element of each array into minheap
3. pop element from minheap and store in ans
    but while popping do insert the next element of
    popped array into minheap

*/