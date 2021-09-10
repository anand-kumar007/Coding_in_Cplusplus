/* 
given N strings print all unique strings in lexicographic
order 


without maps this is pretty tough question!!

*/

#include <iostream>
#include <map>
#include <vector>
using namespace std;

void print_string(vector<string> v)
{
    auto it = v.begin();
    for (it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
int main()
{
    int N;
    cout << "enter N : ";
    cin >> N;
    vector<string> v(N);

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }

    cout << "strings are :" << endl;
    print_string(v);

    cout << "\tUnique and Lexicographically sorted strings are : \n";

    map<string, string> m;
    for (auto i = v.begin(); i != v.end(); i++)
    {
        m.insert({*i, ""});
    }

    for (auto value : m)
    {
        cout << value.first << endl;
    }
    return 0;
}