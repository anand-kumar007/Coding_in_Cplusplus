
//nesting of maps and avoiding the un-necessary values
//In Maps we can choose almost all the complex data type to be key
//where direct comparison is possible like pair,vector,set etc

//But in case of unordered maps we have some limitation of using the key
//bcz they are implemented as hashtables

// same is true for unordered set
//set<pair<int,int>> ==> valid but not in case of unordered set bcz hash functions not defined

#include <bits/stdc++.h>
using namespace std;
void Demo1();

int main()
{
    Demo1();
    return 0;
}

void Demo1()
{
    map<pair<string, string>, vector<int>> m;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string fn, ln;
        int sub;
        cin >> fn >> ln >> sub;

        for (int j = 0; j < sub; j++)
        {
            int x;
            cin >> x;
            m[{fn, ln}].push_back(x);
        }
    }

    cout << "\n-------------------\n";

    for (auto &ele : m)
    {
        auto &full_name = ele.first;
        auto &list = ele.second;

        cout << full_name.first << " " << full_name.second << endl;
        cout << list.size() << endl;

        for (auto &mark : list)
            cout << mark << " ";
        cout << endl;
    }

    // i/p:
    // 3
    // Anand Kumar 4
    // 10 20 30 40
    // Ashok Kumar 3
    // 30 40 50
    // Manish Rathore 5
    // 40 50 60 70 70
}