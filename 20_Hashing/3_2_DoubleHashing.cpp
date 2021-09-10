

/* implement a double hash right from scratch */

#include <iostream>
using namespace std;
#define PRIME 7
#define TABLESIZE 13

class DoubleHash
{
    int curr_size;
    int *hashTable;

public:
    int hash1(int key) const { return (key % TABLESIZE); }
    int hash2(int key) const { return (PRIME - key % PRIME); }
    bool isFull() const { return curr_size == TABLESIZE; }
    DoubleHash()
    {
        curr_size = 0;
        hashTable = new int[TABLESIZE];
        for (int i = 0; i < TABLESIZE; i++)
            hashTable[i] = -1;
    }
    //utiltily function
    void search(int key);
    void insert(int key);
    void displayHash();
};

int main()
{
    int a[] = {19, 27, 36, 10, 64, 20};
    int n = sizeof(a) / sizeof(a[0]);

    DoubleHash h;

    for (int i = 0; i < n; i++)
    {
        h.insert(a[i]);
    }
    // searching some keys
    h.search(36);  // This key is present in hash table
    h.search(100); // This key does not exist in hash table

    h.displayHash();
    return 0;
}

void DoubleHash::displayHash()
{
    for (int i = 0; i < TABLESIZE; i++)
    {
        if (hashTable[i] != -1)
            cout << i << " --> " << hashTable[i] << endl;
        else
            cout << i << endl;
    }

    return;
}

void DoubleHash::search(int key)
{
    int idx1 = hash1(key);
    int idx2 = hash2(key);

    int i = 0;

    int newIdx = (idx1 + i * idx2) % TABLESIZE;

    while (hashTable[newIdx] != key)
    {
        if (hashTable[newIdx] == -1)
        {
            cout << "not found !" << endl;
            return;
        }

        i++;
        newIdx = (idx1 + i * idx2) % TABLESIZE;
    }

    cout << key << " found! " << endl;
    return;
}

void DoubleHash::insert(int key)
{
    if (isFull())
        return;

    int idx1 = hash1(key);

    if (hashTable[idx1] == -1)
        hashTable[idx1] = key;
    else
    {
        int idx2 = hash2(key);
        int i = 1;
        while (1)
        {
            int newIdx = (idx1 + i * idx2) % TABLESIZE;

            if (hashTable[newIdx] == -1)
            {
                hashTable[newIdx] = key;
                break;
            }
            i++;
        }
    }
    curr_size++;
}

/* 

Double hashing is a collision resolving technique(open addressing one):

Double hashing can be done using :
(hash1(key) + i * hash2(key)) % TABLE_SIZE
Here hash1() and hash2() are hash functions and TABLE_SIZE
is size of hash table.

A popular second hash function is : hash2(key) = PRIME – (key % PRIME) 
where PRIME is a prime smaller than the TABLE_SIZE.

A good second Hash function is:

1. It must never evaluate to zero
.2 Must make sure that all cells can be probed

*/
