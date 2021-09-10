

/* The Hashing in C++ is generally implemented using
1. map 
2. unorderd_map

Points       map        |    unordered_map
                
insert  |   O(log(n))       O(1)
access  |   O(log(n))       O(1)
delete  |   O(log(n))       O(n)
implem..    RedBlackTree    HashTables

maps==> in ascending order of the keys
unordered_map => random order not even the order of insertion

*/

#include <iostream>
#include <map>
using namespace std;

int main()
{
    return 0;
}

/* 

Differences between hash table and STL map

Null Keys : STL Map allows one null key and multiple null values whereas hash table doesn’t allow any null key or value.

Thread synchronization : Map is generally preferred over hash table if thread synchronization is not needed. Hash table is synchronized.

Thread safe: STL Maps are not thread safe whereas Hashmaps are thread safe and can be shared with many threads.

Value Order : In STL map, values are stored in sorted order whereas in hash table values are not stored in sorted order

Searching Time : You can use STL Map or binary tree for smaller data( Although it takes O(log n) time, the number of inputs may be small enough to make this time negligible) and for large amount of data, hash table is preferred.

*/