#include <iostream>
using namespace std;
void generateNthrow(int N);
void Pascal(int rows);
void Pascal2(int rows);

int main()
{
    int N = 5;
    generateNthrow(N);
    cout << "\n-----------\n";
    Pascal2(N + 1);
    return 0;
}

void generateNthrow(int N)
{
    // nC0 = 1
    int prev = 1;
    cout << prev;

    for (int i = 1; i <= N; i++)
    {
        // nCr = (nCr-1 * (n - r + 1))/r
        int curr = (prev * (N - i + 1)) / i;
        cout << ", " << curr;
        prev = curr;
    }
}

void Pascal(int rows)
{
    //idea here is to calculate C(i,j+1) using C(i,j)
    // we get the following relationship C(i,j+1) = C(i,j)*(i-j+1)/j;
    /*
    C(line,j) = line! / ((line-j)! * j!)
    and 
    C(line,j-1) = line! / (line-j+1)! * (j-1)!
    We can derive following expression from above two expressions.
   
    C(line,j) => C(line,j-1) * (line-j+1)/j
    */
   
    int coff = 1;
    for (int i = 0; i < rows; i++)
    {
        coff = 1;
        for (int j = 0; j <= i; j++)
        {
            if (i == 0 || j == 0)
                coff = 1;
            else
                coff = (coff * (i - j + 1)) / j;

            cout << coff << " ";
        }
        cout << endl;
    }

    return;
}

void Pascal2(int rows)
{
    for (int i = 1; i <= rows; i++)
    {
        int coff = 1; //initially 1 everytime
        for (int j = 1; j <= i; j++)
        {
            cout<<coff<<" ";
            coff = coff * (i - j) / j;
        }
        cout << endl;
    }

    return;
}