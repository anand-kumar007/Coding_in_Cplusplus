
/* pair */

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    pair<int, string> p1;
    // p1 = make_pair(10,"abc");
    p1 = {10, "abc"};

    pair<int, string> &p2 = p1;
    p2.first = 20; //no change in p1 if without ref else p1 will also change
    cout << p1.first << " " << p1.second << endl;

    int arr1[] = {1, 2, 3};
    int arr2[] = {10, 20, 30};
    pair<int, int> p_array[3];

    p_array[0] = {1, 10};
    p_array[1] = {2, 20};
    p_array[2] = {3, 30};

    swap(p_array[0], p_array[2]);
    //we don't have to maintain relation
    //explicitly now
    for (int i = 0; i < 3; i++)
    {
        cout << p_array[i].first << " " << p_array[i].second << endl;
    }
    return 0;
}

/*
used when two things are related to each other
*/
