/*
Sorting the vector
and other methods as well
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Reverse(vector<int> v);
vector<int> Asc(vector<int> v);
vector<int> Desc(vector<int> v);

void Print(vector<int> v)
{
    for (auto i : v)
        cout << i << " ";
    cout << endl;
}

int main()
{
    int n;
    cout << "enter vector size : ";
    cin >> n;

    vector<int> v(n);

    cout << "enter " << n << " vector elements : ";

    for (int i = 0; i < v.size(); i++)
        cin >> v[i];

    cout << "Reversed vector is : " << endl;
    v = Reverse(v);
    Print(v);

    cout << "In ascending order ";
    v = Asc(v);
    Print(v);

    cout << "In descendign order ";
    v = Desc(v);
    Print(v);

    return 0;
}

vector<int> Reverse(vector<int> v)
{
    //reverse from start to end(not included)
    reverse(v.begin(), v.end());
    return v;
}

vector<int> Asc(vector<int> v)
{
    sort(v.begin(), v.end());
    return v;
}

vector<int> Desc(vector<int> v)
{
    sort(v.begin(), v.end(), greater<int>());
    return v;
}

/*
----------------------  reverse()---------------------------------------------------
It reverses the order of the elements in the range [first, last) of any container. The time complexity is O(n). 
Note: The range used is [first, last), which contains all the elements between first and last, including the element pointed by first but not the element pointed by last.

Input : 10 11 12 13 14 15 16 17
Output :10 11 12 13 14 17 16 15
Explanation:
reverse(v.begin() + 5, v.begin() + 8);
In the above function, input we have applied reverse() on the vector
from index 5 to index 7.
Therefore when we display the vector we get reverse order
from index 5 to index 7.

------------------------- sort() --------------------------------------
The time complexity of std::sort() is:
1. Best Case – O(N log N)
2. Average Case – O(N log N)
3. Worst Case – O(N log N)
Space Complexity – It may use O( log N) auxiliary space.
------------------

same two ways like above for asc and desc
sort(arr,arr+n) --> asc
sort(arr, arr+n, greater<int> ()) --> desc

and for particular order you can pass your own
comparison method as well


vector<int> vec2{4, 5, 6, 7};
*/