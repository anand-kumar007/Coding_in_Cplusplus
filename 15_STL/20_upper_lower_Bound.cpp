
/* 
upper and lower bound in STL C++

Iterator lower_bound (Iterator first, Iterator last, const val) 
Iterator upper_bound (Iterator first, Iterator last, const val) 

lower_bound returns an iterator pointing to the first element in the range [first,last) which has a value not less than ‘val’. 

upper_bound returns an iterator pointing to the first element in the range [first,last) which has a value greater than ‘val’. 

so in lower bound if value exist than value may come otherwise higher value

while in upper bound always higher value will come


NOTE :: use sorted vectors or arrays always otherwise these methods won't work

in case of vectors and binary search uses binary seach while for others
generally uses tree traversal
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Array_Lower_Bound();
void Array_Upper_Bound();
void Vector();

int main()
{
    // Array_Lower_Bound();
    // Array_Upper_Bound();
    Vector();
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

    if (it == v.end())
    {
        cout << "NOT FOUND !!" << endl;
    }
    else
    {
        cout << *it << endl;
    }
}