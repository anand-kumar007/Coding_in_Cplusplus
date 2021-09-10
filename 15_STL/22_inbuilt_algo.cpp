/* STL algorithms  
1. min and max elements in array and vectors etc
2. accumulate gives sum of the array or vector takes third arg as inital sum
3. count() returns count of specified element taken as third arg
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h> //for accumulate
using namespace std;
int main()
{
    int n;
    cout << "enter n : ";
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }

    //most widely used for reversing vector,strings and arrays
    reverse(v.begin(), v.end());
    // reverse(v.begin()+2, v.end());
    cout << "reversed vector is : " << endl;
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    string s = "Anand";
    reverse(s.begin(), s.end());
    cout << "reversed string is : " << s << endl;

    //these functions returs iteratots or pointer
    int min = *min_element(v.begin() + 2, v.end());
    int max = *max_element(v.begin(), v.end());

    cout << "min : " << min << "\nmax : " << max << endl;

    int sum = accumulate(v.begin(), v.end(), 0);
    cout << "vector sum : " << sum << endl;

    int ct = count(v.begin(), v.end(), 30);
    cout << "count of 30 is : " << ct << endl;

    //will return the iterator
    auto it = find(v.begin(), v.end(), 30);

    if (it == v.end())
    {
        cout << "30 not found !!" << endl;
    }
    else
    {
        cout << "found element is : " << *it << endl;
    }
    return 0;
}