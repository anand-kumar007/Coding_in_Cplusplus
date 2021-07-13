/*
calculate n power p using recursion
*/
#include <iostream>
using namespace std;
unsigned long long int NPowerP(int n, int p);

int main()
{
    int n, p;
    cout << "ENTER N AND P : ";
    cin >> n >> p;
    cout << NPowerP(n, p) << endl;

    return 0;
}

unsigned long long int NPowerP(int n, int p)
{
    if (p == 0)
        return 1;

    return n * NPowerP(n, p - 1);   
}