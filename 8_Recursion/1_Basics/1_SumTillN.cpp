/*
Recursion means function calling itself
and making the problem shorter everytime and
stopping at some final condition.
sum till N : n + n-1 + n-2 + n-3 + n-4 + .....+1
sum till N : n + sum till n-1
sum till N-1 : n-1 + sum till n-2
:               :
:               :
:               :
sum till 1  :   1
*/
#include <iostream>
using namespace std;
int Sum(int n)
{
    if(n==1)
    return 1;
    else
    return n + Sum(n-1);
}
int main()
{
    int n;
    cout << "Enter N : ";
    cin >> n;
    cout<<Sum(n)<<endl;
    return 0;
}
