/*
Given n strings print them in the sorted order

can use maps but no need since frequency etc is not asked

*/

#include <iostream>
#include <set>
using namespace std;

void print_set(set<string> &st)
{
    for (auto item : st)
    {
        cout << item << endl;
    }
}
int main()
{
    int n;
    cout << "Enter N : ";
    cin >> n;
    set<string> st;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        st.insert(s);
    }

    cout << "Lexicographich order : " << endl;
    print_set(st);
    return 0;
}