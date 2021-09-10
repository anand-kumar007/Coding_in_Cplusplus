/* 
maps, unordered maps and multisets 

Each element of a map is a pair 
in vectors these values are stored side by side
while in case of maps these are not stored side by side

so we cannot do it+1 in case of maps while it++ can be done

All the keys of map are unique

insert and accessing an element takes O(log(N)) time in map

find(3) etc will return iterator to that key if exists
else it would return the map.end()

log(n) time it will take

map(key,value) ==> 
lets say
int, string
1   abc
2   bcd
3   efg

===> maps (or ordered maps) <==
stored in form of red black trees(self balancing trees)

*/

#include <iostream>
#include <map>
using namespace std;

void printMap(map<int, string> m)
{

    for (auto value : m)
    {
        cout << value.first << " "
             << value.second << endl;
    }
    cout << endl;

    return;
}

int main()
{
    map<int, string> m;

    m[3] = "Anand";
    m[5] = "Deepak";
    m[7] = "Sam";
    m.insert(make_pair(6, "Divya"));
    m.insert({2, "Riya"});

    map<int, string>::iterator it;

    for (it = m.begin(); it != m.end(); it++)
    {
        cout << (*it).first << " " << (*it).second << endl;
    }
    cout << endl;
    //in ascending ordr of keys the values are stored !!!!!

    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
    cout << endl;
    m[9]; //will insert the default value for the "string "
    printMap(m);

    //All the keys of map are unique
    m[2] = "Shikha"; //will replace the m[2] value if exist
    printMap(m);

    auto bl = m.find(1);
    if (bl == m.end())
    {
        cout << "No value" << endl;
    }
    else
    {
        cout << (*bl).first << " ";
        cout << (*bl).second << endl;
    }

    // will take either key or iterator value to erase that pair

    m.erase(2); //O(log(n))
    printMap(m);

    auto itr = m.find(6);
    // auto itr = m.find(34); //will give segmentation fault since itr will point to m.end()
    m.erase(itr); //which doesn't exists and cannot be deleted
    printMap(m);

    auto pitr1 = m.find(3);
    auto pitr2 = m.find(5);

    //[start,end) position
    m.erase(pitr1, pitr2);
    printMap(m);

    m.clear();
    printMap(m);
    return 0;
}

// inserting and element to map takes O(n) times

//find,clear,erase works in all containers

// based on comparison in key value is stored take O(logn)

// and hence insertion time sometimes also depends upon key

// if key is string it become s.size()*Log(n) where s.size() is
// size of that string("key") here since string comparison time also considered
