/*
find the factorial using recursion
N! = N*(N-1)!
so on
*/

#include <iostream>
using namespace std;
unsigned long long int factorial(int N);

int main()
{
    int N;
    cout << "Enter N : ";
    cin>>N;
    cout<<factorial(N)<<endl;
    return 0;
}

unsigned long long int factorial(int N)
{
    if(N==0)
    return 1;

    return N * factorial(N-1);
}
