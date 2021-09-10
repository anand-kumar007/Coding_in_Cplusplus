
/* 
    inbuilt sorting method
    sort() takes two iterator as arg and one comparator function

    itr1 => statrting index
    itr2 => ending index 
    NOTE : [itr1, itr2)  while sorting

    nlog(n) time complexity for sorting in worst case
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool my_comparator(pair<int, int> a, pair<int, int> b);
bool i_am_comparator(pair<int, int> a, pair<int, int> b);
void compareOperation(string s1, string s2);
void Array();
void Vector();
void Pair();

int main()
{
    // Array();
    // Vector();
    Pair();
    return 0;
}
void Array()
{
    int arr[] = {1, -4, 34, -29, 4, 20, 300};
    int n = sizeof(arr) / sizeof(arr[0]);

    // sort(arr, arr + n);
    // sort(arr, arr + n-3); //leaves last 3 elements
    sort(arr + 2, arr + n); //leaves first 2 elements
    cout << "sorted array : " << endl;

    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

void Vector()
{
    vector<int> v = {10, -24, 100, 56, 77, 43};
    int n = sizeof(v) / sizeof(v[0]);

    // sort(v.begin(),v.end());
    sort(v.begin(), v.end(), greater<int>()); //descending order
    cout << "sorted vector : " << endl;

    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

void Pair()
{
    vector<pair<int, int>> p = {{1, 3}, {30, 4}, {30, 3}, {-3, 4}, {10, 90}};

    // sort(p.begin(), p.end(), my_comparator); // greater<int> () won't work here since pair
    //notice no arg is passed to my_comparator here

    // sort(p.begin(), p.end());
    sort(p.begin(), p.end(), i_am_comparator);

    cout << "sorted pair : " << endl;

    for (auto i : p)
    {
        cout << i.first << " " << i.second << endl;
    }
}

bool my_comparator(pair<int, int> a, pair<int, int> b)
{
    if (a > b)
        return true;

    return false;

    //since pairs can be directly compared
    //or use
}

bool i_am_comparator(pair<int, int> a, pair<int, int> b)
{
    // if(a.first != b.first)
    // {
    //     if(a.first > b.first) return true;
    //     else
    //     return false;
    // }
    // else
    // {
    //     if(a.second > b.second) return true;
    //     else
    //     return false;
    // }

    // sort in descending order such that if first is not compared
    // compare the second

    //=================================
    // trick to remember is return the thing in which you want to sort

    if (a.first != b.first)
    {
        return a.first > b.first;
    }
    else
    {
        return a.second > b.second;
    }
}

//for string
void compareOperation(string s1, string s2)
{
    // returns a value < 0 (s1 is smaller then s2)
    if ((s1.compare(s2)) < 0)
        cout << s1 << " is smaller than " << s2 << endl;

    // returns 0(s1, is being comapared to itself)
    if ((s1.compare(s1)) == 0)
        cout << s1 << " is equal to " << s1 << endl;
    else
        cout << "Strings didn't match ";
}

/*
sort() method is implemented using introsort()

which is a combo of three sorting techniques viz.
1. quicksort()
2. heapsort()
3. insertionsort()

starts with quicksort and if depth of recursion turns out
to be more it shifts to heap sort 
and if no of elements are less (quite low) it uses insertion sort

*/