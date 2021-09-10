
/*
implement open-addressing hashing
use linear probing as collision resolving techniques 

*/

#include <iostream>
using namespace std;
#define TABLE_SIZE 10

class LinearHash
{
    int curr_size;
    int *hashTable;

public:
    LinearHash()
    {
        curr_size = 0;
        hashTable = new int[TABLE_SIZE];

        for (int i = 0; i < TABLE_SIZE; i++)
            hashTable[i] = -1;
    }
    bool isFull() const { return (curr_size == TABLE_SIZE); }
    int hash(int key) const { return (key) % TABLE_SIZE; }

    void search(int key);
    void insert(int key);
    void displayHash();
};

int main()
{
    int arr[] = {1, 3, 13, 4, 15, 6, 18, 20, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    LinearHash Lh;

    for (int i = 0; i < n; i++)
    {
        Lh.insert(arr[i]);
    }

    Lh.search(8);
    Lh.search(80);

    Lh.displayHash();

    return 0;
}

void LinearHash::displayHash()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hashTable[i] != -1)
            cout << i << " --->" << hashTable[i] << endl;
        else
            cout << i << endl;
    }
}

void LinearHash::search(int key)
{
    int idx = hash(key);
    if (hashTable[idx] == key)
    {
        cout << key << " found" << endl;
        return;
    }
    int i = 1;

    while (hashTable[(idx + i) % TABLE_SIZE] != key)
    {
        if (hashTable[(idx + i) % TABLE_SIZE] == -1)
        {
            cout << "not found " << endl;
            return;
        }
        i++;
    }
    cout << key << " found " << endl;
    return;
}

void LinearHash::insert(int key)
{
    if (isFull())
        return;

    int idx = hash(key);
    if (hashTable[idx] == -1)
        hashTable[idx] = key;
    else
    {
        int i = 1;
        int newIdx = (idx + i) % TABLE_SIZE;

        while (1)
        {

            if (hashTable[newIdx] == -1)
            {
                hashTable[newIdx] = key;
                break;
            }

            i++;
            newIdx = (idx + i) % TABLE_SIZE;
        }
    }

    curr_size++;
}

/* 
advtange of linear probling:
1. No extra space

disadvantage of linear probing :

1. deletion is difficult
2. O(N) search in worst scenario
3. primary clustering
4. secondary clustering


Primary clustering :
groups gets formed here and hence
probabilty of getting filled for next
free slot gets increased.

secondary clustering:

two or more keys follows same probing sequence



===============================================
Quadratic probing
Adv:
1. No extra space
2. No primary clustering

disAdv:
1. secondary clutering still exiss
2. search O(n) in worst case
3. No guarantee of finding the slot 


=================================================
double hashing
adv:
1. primary and secondary clustering resolved
2. guarantees uniform filling of keys

disadv:
1. search is O(n)
*/