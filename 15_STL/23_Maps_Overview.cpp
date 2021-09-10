

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <stdio.h>
using namespace std;

void add_value(map<string, int> &m, string x, int y)
{
    auto it = m.find(x);

    if (it == m.end())
        m[x] = y;
    else
        m[x] = m[x] + y;

    return;
}

void print_marks(map<string, int> &m, string x)
{
    auto it = m.find(x);

    if (it != m.end())
        cout << it->second << endl;
    else
        cout << "0" << endl;

    return;
}

int main()
{

    int q;
    cin >> q;
    int type;
    string x;
    int y;
    map<string, int> m;

    while (q--)
    {
        cin >> type;

        if (type == 1)
        {
            cin >> x >> y;
            add_value(m, x, y);
        }
        else if (type == 2)
        {
            cin >> x;
            m.erase(x);
        }
        else if (type == 3)
        {
            cin >> x;
            print_marks(m, x);
        }
    }
    return 0;
}
