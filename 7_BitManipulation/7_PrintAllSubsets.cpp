/*
Given a set print all its subsets

{a,b,c}
{}  ----->000
{c} ----->001
{b} ----->010
{b,c} --->011
{a}   --->100
{a,c} --->101
{a,b} --->110
{a,b,c} -->111

n objects in set means 1<<n subsets (2^n)
hence 0 to (1<<n) -1 numbers and check where the
bit is set and print the corresponding symbol from set
*/

#include <iostream>
using namespace std;
void subsets(char arr[], int n);
void subset2(char arr[], int n);

int main()
{
    char arr[3] = {'a','b','c'};
    // subsets(arr, 3);
    subset2(arr, 3);

    return 0;
}

void subsets(char arr[], int n)
{
    // 0 to 2^n-1 sets in total
    for(int i=0; i<(1<<n); i++)
    {
        for(int j=0; j<n; j++)
        {
            //check it the Jth bit of Ith number
            //is set(1) or not if it is set then(logic of getBit here )
            //print corresponding symbol from array
            if( i &(1<<j) )
            {
                // cout << arr[j] << " "; 
                // if don't want to maintain the order or 
                //1->a 2->b etc
                cout << arr[n - j - 1] << " ";
            }
        }
        cout<<endl;
    }
}
// O(2^n * n) is the complexity

void subset2(char arr[],int n)
{
    for(int i=0; i< (1<<n); i++)
    {
        for(int j=0; j<n; j++)
        {
            if( (i & (1<<j)) !=0)
            {
                cout<<arr[j]<<" ";
            }

        }cout<<endl;
    }
}