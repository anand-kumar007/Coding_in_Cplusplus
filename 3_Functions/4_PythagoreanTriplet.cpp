/*
limit value : 20 
3 4 5   
5 12 13 
6 8 10  
8 15 17 
9 12 15 
12 16 20
*/

#include <iostream>
#include <cmath>
using namespace std;

bool checkTriplet(int x, int y, int z);
void Pythagoras(int range);
void Pythagoras2(int range);
void BruteForce(int range);

int main()
{
    int range;
    cout << "entet last limit value : ";
    cin >> range;
    // Pythagoras(range);
    BruteForce(range);
    // Pythagoras2(range);

    return 0;
}

// ---------------------------------
// optimzed soln1
void Pythagoras(int num)
{
    int c = 0, c_square = 0;
    for (int i = 1; i <= num; i++)
    {
        for (int j = i; j <= num - 1; j++)
        {
            c_square = i * i + j * j;
            c = sqrt(c_square);

            if (c * c == c_square)
                cout << i << " " << j << " " << c << endl;
        }
    }
}

// --------------------------------------
void BruteForce(int range)
{
    for (int i = 1; i <= range; i++)
    {
        for (int j = i; j <= range; j++)
        {
            for (int k = j; k <= range; k++)
            {
                if (checkTriplet(i, j, k))
                {
                    cout << i << " " << j << " " << k << endl;
                }
            }
        }
    }
}

// ---------------------------------------
// optimized but not recommended

void Pythagoras2(int range)
{
    int a, b, c = 0;
    int m = 2; //starting

    while (c < range)
    {
        //Loop from 1 to m-1
        for (int n = 1; n < m; n++)
        {
            a = m * m - n * n;
            b = 2 * m * n;
            c = m * m + n * n;

            if (c > range)
                break;

            cout << a << " " << b << " " << c << endl;
        }
        m++;
    }

    return;

    //will miss some triplet so don't use
}
// ----------------------------------------------
// Brute force way
bool checkTriplet(int x, int y, int z)
{
    int maxValue = max(x, max(y, z));

    if ((maxValue * maxValue == x * x + y * y) ||
        (maxValue * maxValue == x * x + z * z) ||
        (maxValue * maxValue == z * z + y * y))

        return true;
    else
        return false;
}
