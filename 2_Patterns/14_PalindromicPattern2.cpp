/*
=============================
enter N : 5 (Desired answer)
    1   
   212  
  32123 
 4321234
543212345
=============================
*/
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "enter N : ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        //spaces
        for (int j = 1; j <= n - i; j++)
            cout << " ";

        //decreasing order 
        
        int element = i;
        for(; element>=1; element--)
        cout<<element;

        //increasing order
        for(element = 2; element<=i; element++)
        cout<<element;

        cout << endl;
    }
    return 0;
}