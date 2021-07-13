/*
permutation using c++ inbuilt function
enter n : 3
enter elements : 1 1 2
112
121
211
*/

#include <iostream>
#include <vector>    //for vectors
#include <algorithm> //for sort()
using namespace std;
int main()
{
    int n;
    cout << "enter n : ";
    cin >> n;
    vector<int> a(n);

    cout << "enter elements : ";
    for (auto &i : a)
    {
        cin >> i;
    }

    //sort the array first
    sort(a.begin(), a.end());

    //store output in ans
    vector<vector<int>> ans;

    do
    {
        ans.push_back(a);
    } while (next_permutation(a.begin(), a.end()));

    //print the answer

    for (auto v : ans)
    {
        for (auto i : v)
            cout << i;
        cout << endl;
    }

    return 0;
}