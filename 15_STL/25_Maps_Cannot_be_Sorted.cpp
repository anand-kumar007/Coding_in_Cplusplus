#include<bits/stdc++.h>
using namespace std;

bool myComp(pair<int, int> &p1, pair<int, int> &p2)
{

    return p1.second < p2.second;

}

// Function to sort the map according
// to value in a (key-value) pairs

void sort(map<int, int> &M)
{

    vector<pair<int, int>> A;

    // Copy key-value pair from Map
    // to vector of pairs
    for (auto &it : M)
    {
        A.push_back(it);
    }

    // Sort using comparator function
    sort(A.begin(), A.end(), myComp);
    // Print the sorted value
    for (auto &it : A)
    {

        cout << it.first << ' '
             << it.second << endl;
    }
    return ;
}
int main()
{

    map<int, int> m1;
    map<int, int> m2;

    m1.insert({2,24});
    m1.insert({3,23});
    m1.insert({5,3});
    m1.insert({6,5});

    m1[23] =232;
    m2.insert({3,45});
    m2.insert({4,3});
    m2.insert({2,-2});
    m2.insert({1,2});


    // error maps are associative containers we cannot sort them using this way
    // sort(m1.begin(),m1.end());
    // sort(m2.begin(),m2.end());

    // we can use our own method to sort them
    sort(m1);
    sort(m2);

    // for(auto item : m1)
    //     cout<<item.first<<" "<<item.second<< " -- ";

    // cout<<endl;
    // for (auto item : m2)
    //     cout << item.first << " " << item.second << endl;

    // for(auto it = m1.begin(); it != m1.end(); it++)
        // cout<< (it->first) <<" "<< (it->second) <<endl;


    return 0;
}

