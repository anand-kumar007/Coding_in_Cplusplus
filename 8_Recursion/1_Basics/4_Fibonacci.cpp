/*
print first N fibonacii and Nth fibonacii
Number using two separate functions 
and using recursion
*/

#include <iostream>
using namespace std;
void FibonaciiSeries(int n);
int fib(int n);
int fib2(int n);

int main()
{
    int n;
    cout << "Enter N : ";
    cin>>n;

    FibonaciiSeries(n);
    cout<<endl;
    //if wanna match with countings call it with n-1
    // cout << "Nth fibonacii Number is : " << fib(n) << endl;
    cout << "Nth fibonacii Number is : " << fib2(n) << endl;

    return 0;
}

void FibonaciiSeries(int n)
{
    if(n==0)
    return ;

    static int t1=0,t2=1,t3;
    cout<<t1<<" "; 
    
    t3 = t1+t2;
    t1=t2;
    t2 = t3;
    FibonaciiSeries(n-1);

}

int fib(int n)
{
   if(n==0 || n==1)
   return n;

    return fib(n-1) + fib(n-2);
}
//the time complexity is exponential for this and hence not recommended
//better to do by iterative or O(N) space complexity method

int fib2(int n)
{
        int t1 = 0, t2 = 1;
        int nextTerm = t1 + t2;

        if(n==1)
        return 0;
        else if(n==2)
        return 1;

        for (int i = 3; i <= n; ++i)
        {
            t1 = t2;
            t2 = nextTerm;
            nextTerm = t1 + t2;
        }

        //if counting is considred else return nextTerm
        return t2;
 }
