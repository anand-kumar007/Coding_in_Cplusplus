

/*
only distict permutation 
//Note pass the sorted array into the function

enter N : 4
enter n values : 1 1 2 2
1122
1212
1221
2112
2121
2211

*/
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> ans;

void helper(vector<int> a, int idx)
{
    if (idx == a.size())
    {
        ans.push_back(a);
        return;
    }

    for (int i = idx; i < a.size(); i++)
    {
        if (i != idx and a[i] == a[idx])
            continue;

        swap(a[i], a[idx]);
        helper(a, idx + 1);
    }
}

int main()
{

    int n;
    cout << "enter N : ";
    cin >> n;
    vector<int> a(n);
    cout << "enter n values : ";
    for (auto &v : a)
    {
        cin >> v;
    }

    //get the permutations
    helper(a, 0);

    //print the permutations
    for (auto v : ans)
    {
        for (auto i : v)
        {
            cout << i;
        }
        cout << endl;
    }
    return 0;
}