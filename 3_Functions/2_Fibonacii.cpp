#include<iostream>
using namespace std;
void PrintFibonacii (int );
int main()
{
    int n;
    cout<<"enter N : ";
    cin>>n;

    cout<<"first "<<n<<" fibonacci Numbers are : "<<endl;
    PrintFibonacii(n);
    return 0;
}

void PrintFibonacii(int num)
{
    int t1=0,t2=1,t3;

    for(int i=1; i<=num; i++)
    {
        cout<<t1<<" ";
        t3 = t1 + t2;
        t1 = t2;
        t2 = t3;
    }
}