/*
Pair is a container to store a pair of two values
holding some relation ship btwn them
*/
/*
Given an array reduce it in such a way that
@ smallest element put 0
@ next larger element put 1
..............so on

ex: {10,16,7,14,5,3,12,9}
o/p: {4,7,2,6,1,0,5,3}
==========
One way is sort them then replace with 0,1, etc and then
place them accordingly
-->
use pair containe cz index and value at that index holds a relation
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool MyCompare(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first < p2.first;
}
void Reduce_array(int arr[], int n);

int main()
{
    int arr[] = {10, 16, 7, 14, 5, 3, 12, 9};
    int n = 8;

    Reduce_array(arr, n);
    return 0;
}

void Reduce_array(int arr[], int n)
{
    vector<pair<int, int>> v;

    //store indices and correspondig value in vector
    for (int i = 0; i < n; i++)
    {
        // v.push_back(make_pair(arr[i],i));
        //          OR

        pair<int, int> p;
        p.first = arr[i];
        p.second = i;
        v.push_back(p);
    }

    //sort the vector according to values and indices remainign intact
    sort(v.begin(), v.end(), MyCompare);

    //now just pick the index and place 0,1,2,....

    for (int i = 0; i < n; i++)
    {
        arr[v[i].second] = i;
    }

    cout << "reduced array is  : " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
}