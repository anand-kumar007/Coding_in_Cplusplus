/*
Given weights and values of n items, put these items in a 
knapsack of capacity W to get the maximum total value in 
the knapsack. In other words, given two integer arrays val[0..n-1] 
and wt[0..n-1] which represent values and weights associated with 
n items respectively. Also given an integer W which represents 
knapsack capacity, find out the maximum value subset of val[] 
such that sum of the weights of this subset is smaller than or 
equal to W. You cannot break an item, either pick the complete 
item or don’t pick it (0-1 property).

*/

#include <iostream>
using namespace std;
int knapsack(int val[],int wt[],int n,int W);

int main()
{
    int val[] = {100,50,150};
    int wt[] = {10,20,30};
    int n=3;
    int W = 50;

    //get the maxm value comibnation
    cout << knapsack(val,wt,3,W);
    return 0;
}

//soln is simple
//one time let we are considering nth item
//do modification in accordingly

//second case may be let we don't consider nth
//item

int knapsack(int val[], int wt[], int n, int W)
{
    if(n==0 || W==0)
        return 0;
    //check for the first case
    if(wt[n-1] > W)
        return knapsack(val,wt,n-1,W);

    return max((knapsack(val,wt,n-1,W-wt[n-1])+ val[n-1]),
                knapsack(val,wt,n-1,W));

}