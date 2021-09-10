
/*
unordred maps 
1. all methods of ordred maps are there
2. while printing we'll see random ordred storage of them
   not the way in which we insert or any other sorted way
   may follow some sorted order but we'll not be aware of that

differ in
(a) in-built implementation
    uses hash tables in contrast to ordered map which used red-black trees
    for each key a corresponding hash is created !!

(b) time complexity
    O(1) for access and insertion mostly for avg cases
    erase find etc all becomes O(1)
(c) valid data keys datatype 
    not all combo of data types can be used unlike map

    unordered_map<pair<int,int>>, string> m;
    will not support

    cz of the default implementaion 
    eg; can't define hash function for pair(in-built) here
    there not used


    in ordere map we can directly compare pairs, vectors and all
    that's why allowed
*/

/*
    Given n strings and q queries print the frequencies of queried strings


*/

#include <iostream>
#include <map>
#include <unordered_map>
//notice here
using namespace std;

void printMap(unordered_map<int, string> m)
{

    for (auto pr : m)
    {
        cout << pr.first << " " << pr.second << endl;
    }
}

int main()
{
    // unordered_map<int,string> m;

    // m[3] = "sam";
    // m[2] = "rohan";
    // m[3] = "riya";
    // m[10] = "siya";

    // printMap(m);

    // unordered_map<pair<int,int>, string> kmap;
    // throws error

    // question here

    int n;
    unordered_map<string, int> m;
    cout << "Enter N : ";
    cin >> n;
    cout << "enter " << n << "strings : ";
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        //store in the map
        m[s]++;
    }

    int q;
    cout << "enter total queries : ";
    cin >> q;

    while (q--)
    {
        string s;
        cin >> s;

        cout << m[s] << endl;
    }

    return 0;
}

/*
multimap 
==> allows storing the duplicate values as well
other implementaion and all is similar to map only


so 
==> if time is important not the order ==> use unordered_map
==> if duplicates are also needed ==> use multimap
==> if order is necessary use map
*/