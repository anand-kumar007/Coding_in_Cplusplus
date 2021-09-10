
/* 

NOTE :: use sorted vectors or arrays always otherwise these methods won't work

auto it = lower_bound(s.begin(),s.end());
avoid this in case of sets and maps especially
cz it is not log(n) if this notation is used !! it become O(n)

rather use this

auto it = s.lower_bound(value); 


in case of vectors and binary search uses binary seach while for others
generally uses tree traversal
*/

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

void Array_Lower_Bound();
void Array_Upper_Bound();
void Vector();

//already sorted
void Sets();
void Maps();
// for pairs
// for strings

int main()
{
    // Array_Lower_Bound();
    // Array_Upper_Bound();
    // Vector();
    // Sets();
    Maps();
    return 0;
}

void Array_Lower_Bound()
{
    int arr[] = {4, 5, 5, 7, 8, 25};
    int n = sizeof(arr) / sizeof(arr[0]);

    //sorting (must step)
    sort(arr, arr + n);

    int *ptr;
    // ptr = lower_bound(arr, arr + n, 5); //will return 5
    // ptr = lower_bound(arr, arr + n, 26); // will return arr+n
    // ptr = lower_bound(arr, arr + n, 7); // will return 7
    // ptr = lower_bound(arr, arr + n, 6); // will return 7
    ptr = lower_bound(arr, arr + n, 20); // will return 25

    if (ptr == arr + n)
    {
        cout << "NOT FOUND !!" << endl;
    }
    else
    {
        cout << *ptr << endl;
    }
    return;
}

void Array_Upper_Bound()
{
    int arr[] = {4, 5, 5, 7, 8, 25};
    int n = sizeof(arr) / sizeof(arr[0]);

    //sorting (must step)
    sort(arr, arr + n);

    int *ptr;
    ptr = upper_bound(arr + 3, arr + n, 5); //will return 7
    // ptr = upper_bound(arr, arr + n, 26); // will return arr+n
    // ptr = upper_bound(arr, arr + n, 7); // will return 8
    // ptr = upper_bound(arr, arr + n, 6); // will return 7
    // ptr = upper_bound(arr, arr + n, 20); // will return 25

    if (ptr == arr + n)
    {
        cout << "NOT FOUND !!" << endl;
    }
    else
    {
        cout << *ptr << endl;
    }
    return;
}

void Vector()
{
    vector<int> v = {10, 20, -23, -2, 30, 233, 32};

    sort(v.begin(), v.end()); // -23,-2,10,20,30,32,233

    auto it = v.begin(); //for deduing the type of it

    // it = lower_bound(v.begin(), v.end(), 20); //will return 20
    // it = lower_bound(v.begin(), v.end(), 21); //will return 30
    // it = lower_bound(v.begin(), v.end(), 200); //will return 233
    it = lower_bound(v.begin(), v.end(), 30); //will return 30

    //log(n) time complexity

    if (it == v.end())
    {
        cout << "NOT FOUND !!" << endl;
    }
    else
    {
        cout << *it << endl;
    }
}

void Sets()
{
    set<int> s;
    s.insert(100);
    s.insert(200);
    s.insert(40);
    s.insert(30);
    s.insert(-2);

    //-2,30,40,100,200

    // auto it = s.lower_bound(101); //will return 200
    // auto it = s.lower_bound(45); //will return 100
    // auto it = s.lower_bound(-1); //will return 30
    auto it = s.lower_bound(-2); //will return -2

    if (it == s.end())
    {
        cout << "NOT FOUND !!" << endl;
    }
    else
    {
        cout << *it << endl;
    }
}

void Maps()
{
    map<int, int> m;
    m[1] = 100;
    m[5] = 200;
    m[19] = 300;
    m[40] = 400;
    m[3] = 500;
    m[7] = 600;

    // 1->100, 3->500, 5->200,  7->600, 19->300, 40->400

    cout << "------------------" << endl;
    for (auto key_value : m)
    {
        cout << key_value.first << " ->" << key_value.second << endl;
    }

    //bounds are checked on keys in case of maps (we are printing first only)
    //   auto it = m.upper_bound(3); //will return 5
    //   auto it = m.upper_bound(7); //will return 19
    //   auto it = m.upper_bound(40); //will return NOT FOUND
    auto it = m.upper_bound(2); //will return 3

    if (it == m.end())
    {
        cout << "NOT FOUND !!" << endl;
    }
    else
    {
        cout << (*it).first << endl;
    }
}