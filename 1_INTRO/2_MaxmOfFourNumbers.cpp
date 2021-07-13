#include<iostream>
using namespace std;
void getMax(int a,int b,int c, int d);

int main()
{
    int a,b,c,d;
    cout<<"Enter four Numbers : ";
    cin>>a>>b>>c>>d;
    getMax(a,b,c,d);
    //elimination method
   
}

void getMax(int a, int b, int c, int d)
{
    if (a > b)
    {
        if (a > c)
        {
            if (a > d)
                cout << a;

            else
                cout << d;
        }
        else
        {
            if (c > d)
                cout << c;
            else
                cout << d;
        }
    }
    else
    {
        if (b > c)
        {
            if (b > d)
                cout << b;
            else
                cout << d;
        }

        else
        {
            if (c > d)
                cout << c;
            else
                cout << d;
        }
    }
}