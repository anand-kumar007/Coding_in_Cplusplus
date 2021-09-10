
/*
Catalan Number
T(n) = 2nCn/(n+1) =>
Catalan numbers are a sequence of natural numbers that occurs in many interesting counting problems like following.

Count the number of expressions containing n pairs of parentheses which are correctly matched. For n = 3, possible expressions are ((())), ()(()), ()()(), (())(), (()()).
Count the number of possible Binary Search Trees with n keys (See this)
Count the number of full binary trees (A rooted binary tree is full if every vertex has either two children or no children) with n+1 leaves.
Given a number n, return the number of ways you can draw n chords in a circle with 2 x n points such that no 2 chords intersect.

Catalan numbers satisfy the following recursive formula.        

Following is the implementation of above recursive formula. 

The value of nth catalan number is exponential that makes the time complexity exponential.
Using Dp we can reduce it to O(N^2) and using binomial coff O(N) only
*/

#include <iostream>
using namespace std;

long long Catalan(int n)
{
    if (n <= 1)
        return 1;
    long long ans = 0;

    for (int i = 0; i <= n - 1; i++)
        ans += Catalan(i) * Catalan(n - i - 1);

    return ans;
}

// Returns value of Binomial Coefficient C(n, k)
unsigned long int binomialCoeff(unsigned int n,
                                unsigned int k)
{
    unsigned long int res = 1;

    //a bit of optimization
    if (k > n - k)
        k = n - k;

    // Calculate value of [n*(n-1)*---*(n-k+1)] /
    // [k*(k-1)*---*1]
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (k - i);
    }

    return res;
}

unsigned long int catalan(unsigned int n)
{
    unsigned long int c = binomialCoeff(2 * n, n);
    // return 2nCn/(n+1)
    return c / (n + 1);
}

int main()
{
    // 1 1 2 5 14 42 132 429 1430 4862 16796
    for (int i = 0; i <= 10; i++)
        cout << Catalan(i) << " ";
    cout << endl;
    return 0;
}