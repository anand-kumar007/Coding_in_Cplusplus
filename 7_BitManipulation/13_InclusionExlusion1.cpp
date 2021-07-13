/*
like find total number of divisors
divisible by a,b for number N

Enter N,a,b : 40 5 7
12
*/

#include <iostream>
using namespace std;
int TotalDivisible(int n, int a, int b);

int main()
{
    int N, a, b;
    cout << "Enter N,a,b : ";
    cin >> N >> a >> b;

    cout << "Total Divisors are : " << TotalDivisible(N, a, b) << endl;
    return 0;
}

int TotalDivisible(int n, int a, int b)
{
    int c1 = n / a;
    int c2 = n / b;

    int c3 = n / (a * b);

    return c1 + c2 - c3;
}