// Consider a game where a player can 
// score 3 or 5 or 10 points in a move.
// Given a total score n, find number of 
// distinct combinations to reach the given score.

// idea here is to make a table[n+1] size where table[i]
// stores the ways to reach the score i

#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"enter N : "; cin>>n;
    int table[n+1]={0,0,};

    //base case if N=0;
    table[0]=1;

    //for each move increment the count of table[i]
    //for move 3
    for(int i=3; i<=n; i++)
        table[i] += table[i-3];

    //move 5
    for (int i = 5; i <= n; i++)
        table[i] += table[i - 5];

    // move 10
    for (int i = 10; i <= n; i++)
        table[i] += table[i - 10];


    cout<<"total ways are : "<<table[n];    
    return 0;
}